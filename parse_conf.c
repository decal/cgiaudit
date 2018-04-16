#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"cgiaudit.h"

const char*errmsg="Missing field in ";

void synerr(const char*cfile)
{
	fputs(errmsg,stdout);
	puts(cfile);
	exit(EXIT_FAILURE);
}

CONFINFO*parse_conf(const char*cfile)
{
	FILE*cf;
	register char*p,*p2;
	char*oldp;
	CONFINFO*confinfo,*ptr_cinfo;
	static char buf[CONF_BUF_SIZE];

	confinfo=calloc(1,sizeof(*confinfo));
	if(!confinfo)
		vexit("calloc");

	cf=fopen(cfile,"r");
	if(!cf)
		vexit("Unable to open configuration file");

	ptr_cinfo=confinfo;

	p=NULL;

	while(fgets(buf,sizeof buf,cf))
	{

		if(*buf=='#')
			continue;

		for(p2=buf;*p2&&isspace(*p2);p2++);
		if(!*p2)
			continue;

		if(p)
		{
			ptr_cinfo->next=calloc(1,sizeof(*(ptr_cinfo->next)));
			if(!ptr_cinfo->next)
				vexit("calloc");

			ptr_cinfo=ptr_cinfo->next;
		}

		for(p=p2;*p&&!isspace(*p);p++);
		if(p)
			*p=0;
		else
			continue;

		ptr_cinfo->ents[0]=malloc(strlen(buf)+1);
		if(!((ptr_cinfo)->ents)[0])
			vexit("malloc");
		strcpy(ptr_cinfo->ents[0],buf);

		for(p++;*p&&isspace(*p);p++);
		if(!*p)
			continue;

		for(oldp=p;*p&&!isspace(*p);p++);
		if(p)
			*p=0;
		else 
			continue;

		ptr_cinfo->ents[1]=malloc(strlen(oldp)+1);
		if(!ptr_cinfo->ents[1])
			vexit("malloc");
		strcpy(ptr_cinfo->ents[1],oldp);

		for(p++;*p&&isspace(*p);p++);
		if(!*p)
			synerr(cfile);

		for(oldp=p;*p&&*p!='\r'&&*p!='\n';p++);
		if(p)
			*p=0;
		else
			synerr(cfile);
		
		ptr_cinfo->ents[2]=malloc(strlen(oldp)+1);
		if(!ptr_cinfo->ents[2])
			vexit("malloc");
		strcpy(ptr_cinfo->ents[2],oldp);
	}

	return confinfo;
}
