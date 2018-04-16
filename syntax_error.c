#include<stdio.h>
#include<stdlib.h>

void syntax_error(const char*str,const unsigned int fatal)
{
	fprintf(stderr,"[1] %s - Syntax error in HTML: %s\n",
			fatal?"fatal":"nonfatal",str);

	if(fatal)
		exit(EXIT_FAILURE);
	return;
}
