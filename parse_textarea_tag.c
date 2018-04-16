#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#include"cgiaudit.h"

/* 
	@param pinit Initial pointer
	@param inputinfo Structure to fill with TEXTAREA tag information.
	@return 0 on failure, 1 on success
*/

static const char*err_str="While parsing TEXTAREA tag";

int parse_textarea_tag(char**pinit,TEXTAREAINFO*textareainfo)
{
	char*p=*pinit,*pa[1];

	for(;*p&&isspace(*p);p++);

	if(!*p)
		syntax_error(err_str,1);

	for(;*p&&*p!='>';)
	{
		if(!strncasecmp(p,"NAME",4))
		{
			p+=4;
			pa[0]=p;
			textareainfo->name=isolate_value(pa);
			p=pa[0];
			continue;
		}

		if(!strncasecmp(p,"ROWS",4))
		{
			char*p2;

			p+=4;
			pa[0]=p;
			p2=isolate_value(pa);
			p=pa[0];
			textareainfo->rows=strtoul(p2,(char**)0,10);
			if(errno==ERANGE)
				syntax_error(err_str,1);
			continue;
		}

		if(!strncasecmp(p,"COLS",4))
		{
			char*p2;
			p+=4;
			pa[0]=p;
			p2=isolate_value(pa);
			p=pa[0];
			textareainfo->cols=strtoul(p2,(char**)0,10);
			if(errno==ERANGE)
				syntax_error(err_str,1);
			continue;
		}

		if(!strncasecmp(p,"VALUE",5))
		{
			p+=5;

			textareainfo->value=isolate_value(&p);
			if(!textareainfo->value)
				syntax_error(err_str,0);
		}


		while(*p&&isspace(*p))
			p++;
		if(!*p)
			syntax_error(err_str,1);
		
		p++;
	}

	if(!textareainfo->rows||!textareainfo->cols)
		syntax_error(err_str,1);

	return 1;
}
