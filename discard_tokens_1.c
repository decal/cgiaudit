#include<ctype.h>
#include"cgiaudit.h"

/* 
 * Discard HTML tokens which function as hash pair seperators.
 */ 

static const char*err_str="While parsing tag attribute";

void discard_tokens_1(char**pp)
{
	while(**pp&&isspace(**pp))
		(*pp)++;

	if(!**pp||**pp!='=')
		syntax_error(err_str,1);

	(*pp)++;

	if(**pp=='"')
		(*pp)++;

	if(!**pp)
		syntax_error(err_str,1);
	
	return;
}
