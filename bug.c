#include<stdio.h>
#include<stdlib.h>
void bug(const char*str)
{
	fprintf(stderr,"%s\n",str);
	exit(EXIT_FAILURE);
}
