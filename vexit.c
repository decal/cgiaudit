#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
void vexit(const char*f)
{
	fprintf(stdout,"%s: %s\n",f,strerror(errno));
	exit(EXIT_FAILURE);
}
