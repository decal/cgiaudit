#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"cgiaudit.h"

static const char*err_str="While parsing value from tag attribute";
/*
 * Isolate values from hash pairs in HTML tags.
 *
 * @param porig pointer to the beginning of the value
 * @return c-style representation of the value
 */


/* 
 * Discard HTML tokens which function as hash pair seperators.
 */ 

/* void discard_tokens_1(char**pp)
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
} */

/* #define STR "NAME=BLAH heh"
int main(void){
	char*p=malloc(strlen(STR)+1);
	strcpy(p,STR);
	puts(p+=4);
	puts(isolate_value(&p));
	puts(p);
} */

char*isolate_value(char**porig)
{
	register char*p=*porig;
	char c=0,*val,*oldp;

	while(*p&&isspace(*p))
			p++;

	if(!*p||*p!='=')
		syntax_error(err_str,1);
	p++;

	while(*p&&isspace(*p))
		p++;

	if(*p=='"')
		p+=c=1;

	if(!*p)
		syntax_error(err_str,1);

	oldp=p;

	if(c)
		while(*p&&*p!='"')
			p++;
	else
		while(*p&&!isspace(*p)&&*p!='>')
			p++;

	if(!*p)
		syntax_error(err_str,1);

	c=*p;
	*p=0;

	val=malloc(p-oldp+1);
	if(!val)
		vexit("malloc");
	strcpy(val,oldp);

	*p=c; /* overwrite null for strcpy() with original character */

	*porig=p;

	if(*p=='>')
		return val;

	do p++; while(*p&&isspace(*p));

	*porig=p;

	return val;
}
