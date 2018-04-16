#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<netdb.h>
#include<ctype.h>
#include<unistd.h>
#include<errno.h>
#include"cgiaudit.h"

void ca_putstat(const char*);

/* 
 * Connect to an HTTP server and fill in the info structure after parsing the
 * header while handling redirects. 
 */


/* static char*url;
static void set_new_url(char*newurl)
{
	url=malloc(strlen(newurl)+1);
	if(!url)
		vexit("malloc");
	strcpy(url,newurl);
}

char*get_new_url(void)
{
	return url;
} */

FILE*http_connect(URLINFO*url,HTTPSRVINFO*httpsrvinfo)
{
	int sock,ehr=0;
	struct hostent*he;
	struct sockaddr_in sain;
	static char*hexbuf=NULL;
	static int first_time=1;
	char*qryptr,buf[65536];
	register char*p,*p2;
	FILE*so;

	if(!url||!url->host)
	{
		putchar('\n');
		ca_putstat("Invalid URL (did you include \"http://\"?)\n");
		return NULL;
	}

	he=gethostbyname(options.p?options.p:url->host);
	if(!he)
	{
		printf("\n[%d.%d] Unable to resolve hostname: %s\n",i,n,url->host);
		
		return NULL;
	}

	if(first_time&&options.s)
	{
		int x;
		x=atoi(options.s);
		setmask(x,(struct in_addr*)he->h_addr);
		first_time=!first_time;
	}

	sock=socket(PF_INET,SOCK_STREAM,0);
	if(sock<0)
		vexit("socket");

	sain.sin_family=AF_INET;
	sain.sin_port=htons(options.t?options.t:url->port);
	sain.sin_addr=*((struct in_addr*)he->h_addr);

	if(connect(sock,(struct sockaddr*)&sain,sizeof(sain))<0)
		vexit("connect");

	/* Both CR and LF are needed by the HTTP protocol. */

	if(options.x&&url->query)
	{
		if(!hexbuf)
		{
			hexbuf=malloc(HEX_BUF_SIZE);
			if(!hexbuf)
				vexit("malloc");
		}

		hexencode(url->query,hexbuf,HEX_BUF_SIZE);
		qryptr=hexbuf;
	}
	else
	{
		qryptr=url->query;
	}

	/* word to optyx and iis-zang2.c proxy technique */
	if(options.p)
	{
		sprintf(buf,"GET http://%s:%d/%s%s%s HTTP/1.0\r\n",url->host,url->port,url->path[0]=='/'?url->path+1:url->path,qryptr?"?":"",qryptr?qryptr:"");
	}
	else
	{
		sprintf(buf,"GET %s%s%s HTTP/1.0\r\n",url->path,qryptr?"?":"",qryptr?qryptr:"");
	}

	/* I'm not going to rely on the return value of sprintf() */

	p=buf;
	p+=strlen(p);

	if(options.r)
	{
		printf("[%d.%d] --+-- BEGIN HTTP REQUEST --+--\n",i,n);
	}

	strcpy(p,"Host: ");
	p+=strlen(p);
	strcpy(p,url->host);
	p+=strlen(p);
	strcpy(p,"\r\n");
	p+=strlen(p);
	strcpy(p,"User-Agent: ");
	p+=strlen(p);
	strcpy(p,HTTP_USER_AGENT);
	p+=strlen(p);

	if(options.r)
	{
		puts(buf);
		printf("[%d.%d] --+--  END HTTP REQUEST  --+--\n",i,n);
	}

	strcpy(p,"\r\n");
	p+=strlen(p);

	write(sock,buf,p-buf);

	write(sock,"\r\n",2);	

	so=fdopen(sock,"r");
	if(!so)
		vexit("fdopen");
	
	if(options.r)
		printf("[%d.%d] --+--  BEGIN HTTP REPLY  --+--\n",i,n);

	while(fgets(buf,sizeof(buf),so))
	{
		for(p=buf;*p&&isspace(*p);p++);

		/* 
		 * If the line is blank, it marks the end of the HTTP header.
		 * Let the calling function handle the document that follows. 
		 */
		if(!*p)
			break;

		if(options.r)
			fputs(buf,stdout);

		if(!strncasecmp(p,"HTTP/",5))
		{
			p+=6;
			for(p2=p;*p2&&!isspace(*p2);p2++);
			*p2=0;
			httpsrvinfo->ver=malloc(p2-p+1);
			if(!httpsrvinfo->ver)
				vexit("malloc");
			strcpy(httpsrvinfo->ver,p);

			p2++;
			strncpy(httpsrvinfo->code,p2,3);
			*(httpsrvinfo->code+3)=0;

			p2+=4;
			for(p=p2;*p2;p2++)switch(*p2){case '\r':case'\n':*p2=0;}
			httpsrvinfo->phrase=malloc(strlen(p)+1);
			strcpy(httpsrvinfo->phrase,p);
		}

		if(!strncasecmp(p,"Server:",7))
		{
			p+=8;
			while(isspace(*p))
				p++;

			for(p2=p;*p2&&*p2!='\r'&&*p2!='\n';p2++);
			*p2=0;

			httpsrvinfo->server=malloc(p2-p+1);
			strcpy(httpsrvinfo->server,p);
		}
		if(!strncasecmp(p,"Content-length:",15))
		{
			p+=15;
			while(isspace(*p))
				p++;

			for(p2=p;*p2&&!isspace(*p2);p2++);
			*p2=0;

			httpsrvinfo->content_length=strtol(p,(char**)NULL,10);
			if(errno==ERANGE)
				vexit("strtol");
			if(httpsrvinfo->content_length<0)
			{
				fprintf(stderr,"ERROR: HTTP Content-Length is negative!\n");
				exit(EXIT_FAILURE);
			}
		}
	
		if(!strncasecmp(p,"Location:",9))
		{
			URLINFO*urlarg;

			p+=9;
			while(isspace(*p))
				p++;
			
			for(p2=p;*p2&&!isspace(*p2);p2++);
			*p2=0;

			/* First level of verbosity */
			fprintf(stderr,"[%d.%d] Server redirect: %s\n",i,n,p);

			urlarg=parse_url(p);

			if(!urlarg||!urlarg->host)
			{
				fprintf(stderr,"[%d.%d] ERROR: Cannot parse URL from Location field in HTTP header: %s\n",i,n,*p?p:"null");
				exit(EXIT_FAILURE);
			}

			url->host=urlarg->host;

			/* set_new_url(p); */

			if(options.r)
			{
				printf("[%d.%d]  --+--   END HTTP REPLY   --+--\n",i,n);
				ehr=1;
			}

			return http_connect(urlarg,httpsrvinfo);
		}

	}

	if(options.r&&!ehr)
	{
		printf("[%d.%d] --+--   END HTTP REPLY   --+--\n",i,n);
	}

	return so;
}
