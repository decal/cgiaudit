#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#include"cgiaudit.h"

/* 
	@param pinit Initial pointer
	@param inputinfo Structure to fill with INPUT tag information.
	@return 0 on failure, 1 on success
*/
	
static const char*err_str="While parsing INPUT tag";

int parse_input_tag(char**porig,INPUTINFO*inputinfo)
{
	char*p=*porig;

	register char*oldp;
	
	while(*p!='>')
	{
		oldp=p;

		if(!strncasecmp(p,"NAME",4))
		{
			p+=4;
			inputinfo->name=isolate_value(&p);
			if(!inputinfo->name)
				syntax_error(err_str,0);
		}

		if(!strncasecmp(p,"VALUE",5))
		{
			p+=5;
			inputinfo->value=isolate_value(&p);
			if(!inputinfo->value)
				syntax_error(err_str,0);
		}

		if(!strncasecmp(p,"CHECKED",7))
		{
			p+=7;
			inputinfo->checked=1;
		}

		if(!strncasecmp(p,"SIZE",4))
		{
			p+=4;
			inputinfo->size=isolate_value(&p);
			if(!inputinfo->size)
				return 1;
		}

		if(!strncasecmp(p,"MAXLENGTH",9))
		{
			char*p2;
			p+=9;
			p2=isolate_value(&p);
			inputinfo->maxlength=strtoul(p2,(char**)0,10);
			if(!inputinfo->maxlength)
				return 1;
			if(errno==ERANGE)
				syntax_error(err_str,0);
			free(p2);
		}

		if(!strncasecmp(p,"SRC",3))
		{
			p+=3; 
			inputinfo->src=isolate_value(&p);
			if(!inputinfo->src)
				return 1;
		}

		if(!strncasecmp(p,"ALIGN",5))
		{
			p+=5;
			inputinfo->align=isolate_value(&p);
			if(!inputinfo->align)
				return 1;
		}

		if(oldp==p)
		{
			if(!isspace(*p))
				do
				{
					if(*p=='>')
						break;
					p++;
				} while(*p&&!isspace(*p));
				
			while(*p&&isspace(*p))
				p++;
		}

		if(!*p)
			syntax_error(err_str,1);
	}
	*porig=p;

	return 1;
}
