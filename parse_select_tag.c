#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#include"cgiaudit.h"

/* 
	@param pinit Initial pointer
	@param inputinfo Structure to fill with SELECT tag information.
	@return 0 on failure, 1 on success
*/

static const char*err_str="While parsing SELECT tag";

int parse_select_tag(char**pinit,SELECTINFO*selectinfo)
{
	char*p=*pinit,*pa[1];

	for(;*p&&isspace(*p);p++);

	if(!*p)
		syntax_error(err_str,1);

	for(;*p&&*p!='>';p++)
	{
		if(!strncasecmp(p,"NAME",4))
		{
			p+=4;
			pa[0]=p;
			selectinfo->name=isolate_value(pa);
			p=pa[0];
		}

		if(!strncasecmp(p,"VALUE",5))
		{
			p+=5;

			selectinfo->value=isolate_value(&p);
			if(!selectinfo->value)
				syntax_error(err_str,0);
		}


		if(!strncasecmp(p,"SIZE",4))
		{
			char*p2;

			p+=4;
			pa[0]=p;
			p2=isolate_value(pa);
			p=pa[0];
			selectinfo->size=strtoul(p,(char**)0,10);
			if(errno==ERANGE)
				syntax_error(err_str,0);
		}

		if(!strncasecmp(p,"MULTIPLE",7))
		{
			p+=7;
			selectinfo->multiple=1;
		}

		while(*p&&!isspace(*p)&&*p!='>')
			p++;
		if(!*p)
			syntax_error(err_str,1);
	}

	return 1;
}
