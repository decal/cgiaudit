#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<ctype.h>
#include<regex.h>
#include<errno.h> /* for debugging only */
#include"cgiaudit.h"

/* typedef struct FORMINFO_def

        char*url;
        char*action;
        char*method;
        char*enctype;
        FIELDINFO*fieldshead;
        struct FORMINFO_def*next;

}
FORMINFO; */

static char*check_reply(FILE*);

FIELDINFO*curfield=NULL;

static REPORTINFO*checkit(FILE*(*f1)(FORMINFO*,char*,URLINFO*,HTTPSRVINFO*),FORMINFO*forminfo,char*attackstr,URLINFO*urlinfo,HTTPSRVINFO*httpsrvinfo)
{

	FILE*so;
	REPORTINFO*reportinfo=NULL;

	reportinfo=calloc(1,sizeof(*reportinfo));
	if(!reportinfo)
		vexit("calloc");

        j=0;

	if(!forminfo->url)
		return NULL;

	do
	{
		/* return field, instead. */
		so=f1(forminfo,attackstr,urlinfo,httpsrvinfo);
		if(!so)
			break;

		if((reportinfo->string=check_reply(so)))
		{
			reportinfo->attack=attackstr;
			reportinfo->forminfo=forminfo;
			reportinfo->fieldinfo=curfield;
			reportinfo->urlinfo=urlinfo;
		}

		j++;

	}while(1);

        /* Okay done with j */
        j=-1;

	return reportinfo->string?reportinfo:NULL;
}

void ca_putstat(const char*s)
{
	if(j>=0)
		printf("[%d.%d.%d] ",i,n,j+1);
	else
		printf("[%d.%d] ",i,n);

	fputs(s,stdout);

	return;
}

typedef struct regexp_list_def
{
	struct regexp_list_def*next;
	regex_t preg;	
} RELIST;

static char*check_reply(FILE*sockfp)
{
	char*buf;
	int ret;
	static regex_t**re_list=NULL;
	regex_t**re_ptr;
	CONFINFO*confptr;

	buf=malloc(HTTP_BUF_SIZE+1);
	if(!buf)
		vexit("malloc");

	if(!re_list)
	{
		for(ret=0,confptr=confinfo;confptr;confptr=confptr->next)
			if(!strcasecmp(confptr->ents[0],"search"))
				ret++;

		re_list=calloc(ret+1,sizeof(*re_list));
		if(!re_list)
			vexit("calloc");

		for(re_ptr=re_list,confptr=confinfo;confptr;confptr=confptr->next)
			if(!strcasecmp(confptr->ents[0],"search"))
			{
				*re_ptr=malloc(sizeof(**re_ptr));
				if(!*re_ptr)
					vexit("malloc");

				if(regcomp(*re_ptr,confptr->ents[1],REG_EXTENDED))
					vexit("regcomp");
				re_ptr++;
			}
	}

	ret=1;

	while(fgets(buf,HTTP_BUF_SIZE,sockfp))
	{
		for(re_ptr=re_list;*re_ptr;re_ptr++)
		{
			ret=regexec(*re_ptr,buf,(size_t)0,NULL,REG_NOSUB);
			if(!ret)
			{
				char*s1,*p1,*namep;
				const char*str="(*POSSIBLE SUCCESS!*) Received: ";

				if(options.v)
				{
					s1=malloc(strlen(str)+strlen(buf)+2);
					if(!s1)
						vexit("malloc");

					p1=s1;
					strcpy(p1,str);
					p1+=strlen(str);
					strcpy(p1,buf);
					p1+=strlen(buf);
					*(1+p1)=0;
		
					ca_putstat(s1);
				}
	
				switch(curfield->type)
				{
					case 'i':
						namep=((INPUTINFO*)curfield->field)->name;
						break;
					case 's':
						namep=((SELECTINFO*)curfield->field)->name;
						break;
					case 't':
						namep=((TEXTAREAINFO*)curfield->field)->name;
						break;
				} /* switch(curfield->type) */

				break; /* possible success, don't try anymore. */

			} /* if(!ret) */
		} /* for(reptr...); */
		if(!ret)
			break;
	} /* while(fgets(...)) */

	return !ret?buf:NULL;
}

REPORTINFO*cgi_audit(FORMINFO*forminfo,URLINFO*cururl)
{
	char*ca_arg;
	size_t ca_len;

	REPORTINFO*reportinfo=NULL,*ret,*cur;
	HTTPSRVINFO httpsrvinfo={0};
	CONFINFO*confptr=confinfo;

	setbuf(stdout,NULL);

	ca_putstat("Testing for vulnerabilities..\n");

	for(;confptr;confptr=confptr->next)
	{
		if(strcasecmp(confptr->ents[0],"string"))
			continue;

		if(options.v)
		{
			ca_len=strlen(confptr->ents[2])+2;
			ca_arg=malloc(ca_len);
			if(!ca_arg)
				vexit("malloc");

			strcpy(ca_arg,confptr->ents[2]);
			*(ca_arg+ca_len-2)='\n';
			*(ca_arg+ca_len-1)='\0';

			ca_putstat(ca_arg);
		}

		ret=checkit(check_tags,forminfo,confptr->ents[1],cururl,&httpsrvinfo);
		if(ret)
		{
			if(reportinfo)
			{
				cur->next=ret;
				cur=cur->next;
				cur->attack=confptr->ents[2];
				memcpy(&(cur->httpsrvinfo),&httpsrvinfo,sizeof(cur->httpsrvinfo));
			}
			else
			{
				cur=reportinfo=ret;
				reportinfo->attack=confptr->ents[2];
				memcpy(&(reportinfo->httpsrvinfo),&httpsrvinfo,sizeof(reportinfo->httpsrvinfo));
			}
		}
	}

/*
 * decided to use regex.h to search for possible positives instead of this:
 *
	while(fgets(buf,sizeof(buf),so))
		for(p=buf;*p;p++)
			if(*p==':')
				if(*++p&&isalnum(*p))
				{
					do p++; while(*p&&isalnum(*p));
					if(*p==':')
						if(*++p&&isalnum(*p))
						{
							do p++; while(*p&&isalnum(*p));
							if(*p==':')
								puts("SUCCESS!");
						}
				}
*/

	ca_putstat("Done with this form!\n");

	return reportinfo;
}
