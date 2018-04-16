#include<stdio.h>
#include"cgiaudit.h"

void show_doc_info(const HTTPCLIINFO*httpcliinfo)
{
	printf("Content Length: %ld",httpcliinfo->content_length);
	printf("Method: %s\n",httpcliinfo->method);
	printf("Enctype: %s\n",httpcliinfo->enctype);
	return;
}
