#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"cgiaudit.h"

void report(const REPORTINFO*reportinfo)
{
	char*p,*oldhost=NULL,*oldpath=NULL;

	putchar('\n');

	if(reportinfo)
		puts("Vulnerabilities found!");
	else
		puts("No vulnerabilities found..");

	for(;reportinfo;reportinfo=reportinfo->next)
	{

		if((oldhost&&strcmp(reportinfo->urlinfo->host,oldhost))||(oldpath&&strcmp(reportinfo->urlinfo->path,oldpath)))
		{
			putchar('\n');
			fputs(reportinfo->urlinfo->scheme,stdout);
			fputs("://",stdout);
			fputs(oldhost=reportinfo->urlinfo->host,stdout);
			fputs(oldpath=reportinfo->urlinfo->path,stdout);
		}

		printf("%-16.16s%-16.16s%-16.16s%-16.16s%-16.16s\n","Form name","Tag type","Tag name","Attack type","Success string");
		printf("%-16.16s",reportinfo->forminfo->name?reportinfo->forminfo->name:"null");

		switch(reportinfo->fieldinfo->type)
		{
			case 'i':
				printf("%-16.16s","INPUT");
				break;
			case 's':
				printf("%-16.16s","SELECT");
				break;
			case 't':
				printf("%-16.16s","TEXTAREA");
				break;
			default:
				bug("Unknown form field type!");
		}

		p=get_field_name(reportinfo->fieldinfo);
		printf("%-16.16s",p?p:"null");

		printf("%-16.16s",reportinfo->attack);

		p=reportinfo->string+strlen(reportinfo->string);
		while(isspace(*p)&&p--!=reportinfo->string);
		*p=0;

		printf("%-16.16s\n",reportinfo->string);
	}

	return;
}
