#include<stdio.h>
#include"cgiaudit.h"

void show_srv_info(const HTTPSRVINFO*httpsrvinfo)
{
	fputc('(',stdout);
	fputs(httpsrvinfo->code,stdout);
	fputc(' ',stdout);
	fputs(httpsrvinfo->phrase?httpsrvinfo->phrase:"",stdout);
	fputs(") ",stdout);

	putchar('\n');

	return;
}
