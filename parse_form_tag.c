#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#include"cgiaudit.h"

/* 
	@param pinit Initial pointer
	@param forminfo structure to fill with FORM tag information
	@return new pointer position
*/

static const char*err_str="While parsing FORM tag";

char*parse_form_tag(char*pinit,FORMINFO*forminfo)
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

		if(!strncasecmp(p,"NAME",4))
		{
			p+=4;
			forminfo->name=isolate_value(&p);
		}

		if(!strncasecmp(p,"METHOD",6))
		{
			p+=6;
			forminfo->method=isolate_value(&p);
		}

		if(!strncasecmp(p,"ACTION",6))
		{
			p+=6;
			forminfo->action=isolate_value(&p);
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
