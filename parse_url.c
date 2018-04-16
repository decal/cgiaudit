/*
 * I was originally going to be lazy and rip this from PHP's parse_url() function.
 * Problems with BSD libc and portability issues with libpcre forced me to write it myself.
 * 
 * - super
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cgiaudit.h"

/* check parse_url returns for fatal errors because of mailto: and such */

/* int main(int argc,char*argv[])
{
	URLINFO*p;
	p=parse_url(argv[1]);
	if(!p)
	{
		puts("parse_url() returned NULL");
	}
	else
	{
		printf("scheme: %s host: %s user: %s pass: %s path: %s query: %s port: %d\n",p->scheme?p->scheme:"null",p->host?p->host:"null",p->user?p->user:"null",p->pass?p->pass:"null",p->path?p->path:"null",p->query?p->query:"null",p->port);
	}

	return(0);
} */


URLINFO*parse_url(char *arg)
{
	URLINFO*ret=NULL;
	register char*p;

	char*str;
	str=malloc(strlen(arg)+1);
	if(!str)
		vexit("malloc");
	strcpy(str,arg);

	ret=calloc(1,sizeof(*ret));
	if(!ret)
		vexit("calloc");
	ret->port=80;

	p=strchr(str,':');
	if(!p||(*(p+1)!='/'))
		return NULL;
	if((ret->scheme=malloc(p-str+1))==NULL)vexit("malloc");
	*p=0;
	strcpy(ret->scheme,str);

	for(p=++p;*p&&*p=='/';p++);
	if(!*p)
		return NULL;
	if(*(p-1)==':')
		/* scheme without double slashes, i.e. mailto */
		return NULL;

	str=p;

	if(!(p=strchr(str,'/')))
	{
		ret->path=malloc(2);
		if(!ret->path)
			vexit("malloc");
		*(ret->path)='/';
		*(ret->path+1)=0;

		if(NULL==(ret->host=malloc(strlen(str)+1)))vexit("malloc");
		strcpy(ret->host,str);
	}
	else
	{
		if(!(ret->host=malloc(p-str+1)))vexit("malloc");
		*p=0;
		strcpy(ret->host,str);
		*p='/';
		ret->path=malloc(strlen(p)+1);
		if(!ret->path)
			vexit("malloc");
		strcpy(ret->path,p);
		p=strchr(ret->path,'?');
		if(p)
		{
			*p=0;
			ret->query=malloc(strlen(++p)+1);
			if(!ret->query)
				vexit("malloc");
			strcpy(ret->query,p);
		}
	}

	/* username:pass@host:port may be nested in the hostname */
	if((p=strchr(ret->host,':'))!=NULL)
	{
		char*p4;

		if((p4=strchr(p+1,'@')))
		{
			char*p2;

			*p4=0;
			ret->pass=malloc(p4-p);
			if(!ret->pass)
				vexit("malloc");
			strcpy(ret->pass,p+1);
			ret->user=malloc(p-ret->host+1);
			if(!ret->user)
				vexit("malloc");
			*p=0;
			strcpy(ret->user,ret->host);

			if((p2=strchr(++p4,':')))
			{
				*p2=0;
				ret->port=(short)atoi(p2+1);
			}	
			ret->host=p4;
		}
		else
		{
			*p++=0;
			ret->port=(short)atoi(p);
		}
	}
        return ret;
}
