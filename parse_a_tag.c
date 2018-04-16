#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#include"cgiaudit.h"
#include<netdb.h>

/* 
	@param h1 host to compare
	@param h2 host to compare
	@return 0 for equality, 1 for inequality
*/

static const char*err_str="While parsing A tag";

static int addr_cmp(char*h1,char*h2)
{
	struct hostent*he1,*he2;
	char**hp1,**hp2;
	unsigned char flg=0;


	he1=gethostbyname(h1);
	if(!he1)
		return 1;
	he2=gethostbyname(h2);
	if(!he2)
		return 1;

	hp1=he1->h_addr_list;
	hp2=he2->h_addr_list;

	while(hp1&&!flg)
	{
		if(!strcmp(*hp1,*hp2))
			flg=1;
		hp1++;
	}

	hp1=he1->h_addr_list;

	while(hp2&&!flg)
	{
		if(!strcmp(*hp1,*hp2))
			flg=1;
		hp2++;
	}

	return flg?0:1;
}

static void nullify(URLINFO*cururl,AINFO*ainfo)
{
		URLINFO*newurl;

		newurl=parse_url(ainfo->href);
		if(!newurl)
		{
			ainfo->href=NULL;
		}
			
		/* Don't spider outside current web space. */
		if(!options.s&&addr_cmp(newurl->host,cururl->host))
		{
			ainfo->href=NULL;
		}

		if(options.s)
		{
			if(!newurl->query||!cururl->query)
				ainfo->href=NULL;
			else
				if(!strcmp(newurl->path,cururl->path)&&
					!strcmp(newurl->host,cururl->host)&&
					!strcmp(newurl->query,cururl->query))
				ainfo->href=NULL;
		}
		else if(!strcmp(newurl->path,cururl->path)&&!strcmp(newurl->host,cururl->host))
		{
			ainfo->href=NULL;
		}

		return;
}

/* 
	@param pinit Initial pointer
	@param forminfo structure to fill with A tag information
	@return new pointer position
*/

char*parse_a_tag(char*pinit,AINFO*ainfo,URLINFO*cururl)
{
	char*p=pinit;
	register char*oldp;

	while(*p&&isspace(*p))
		p++;

	if(!*p)
		syntax_error(err_str,1);

	while(*p!='>')
	{
		oldp=p;

		if(!strncasecmp(p,"HREF",4))
		{
			p+=4;
			ainfo->href=isolate_value(&p);
			if(!strncmp(ainfo->href,"http://",7))
			{
				nullify(cururl,ainfo);
			}
			/* Don't process mailto stuffs. :-) */
			else if(!strncmp(ainfo->href,"mailto:",7))
			{
				ainfo->href=NULL;
			}
			else if(*(ainfo->href)=='/')
			{
				char*s1,*s2;
				/*strlen("http://")+sizeof('\0')==8*/
				s1=malloc(strlen(ainfo->href)+strlen(cururl->host)+8);
				strcpy(s1,"http://");
				s2=s1+7;
				strcpy(s2,cururl->host);
				s2+=strlen(cururl->host);
				strcpy(s2,ainfo->href);

				ainfo->href=s1;

				nullify(cururl,ainfo);
			}
			else
			{
				char*s1,*s2;
				s1=malloc(strlen(ainfo->href)+strlen(cururl->host)+strlen(cururl->path)+(cururl->query?strlen(cururl->query):0)+8);
				strcpy(s1,"http://");
				s2=s1+7;
				strcpy(s2,cururl->host);
				s2+=strlen(cururl->host);
				strcpy(s2,cururl->path);
				s2+=strlen(cururl->path);
				strcpy(s2,cururl->query?cururl->query:"");

				ainfo->href=s1;

				nullify(cururl,ainfo);
			}

		}

		if(oldp==p)
		{
			if(!isspace(*p))
				do {
					if(*p=='>')
						break;
					p++;
				} while(*p&&!isspace(*p));

			while(*p&&isspace(*p)) p++;
		}

		if(!*p)
			syntax_error(err_str,1);
	}

	return p;
}
