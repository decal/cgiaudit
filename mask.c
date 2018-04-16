#include<stdio.h>
#include<string.h>
#include<netdb.h>
#include"cgiaudit.h"

/* 
 * bit twiddling operations yanked from nmap and adopted to cgiaudit
 *
 * - super
 */

/* just a driver for testing */

/* int main(void)
{
	struct hostent*he;
	options.v=1;

	he=gethostbyname("www.lame.org");

	setmask(16,he->h_addr);

	if(mask("www.lame.org"))
		puts("success");
	else
		puts("failure");

	return 0;
} */

static unsigned int netbits=24;
static struct in_addr orig_addr,start_addr,end_addr;

int setmask(int m,struct in_addr*new_addr)
{
	if(m>32||m<0)
		return 0;

	netbits=m;

	orig_addr.s_addr=ntohl(new_addr->s_addr);

  	start_addr.s_addr = orig_addr.s_addr & (unsigned long) (0 - (1<<(32 - netbits)));
  	end_addr.s_addr = orig_addr.s_addr | (unsigned long)  ((1<<(32 - netbits)) - 1);

	return 1;
}

/* ipv4 netmask test */

int mask(char*host)
{
	struct in_addr test_addr;
	struct hostent*he;

	he=gethostbyname(host);
	if(!he)
	{
		if(options.v)
			fprintf(stderr,"[%d.%d] Unable to resolve host (%s) referenced by A tag.\n",1,1,host);
		return 0;
	}

	test_addr.s_addr=ntohl((*((struct in_addr*)he->h_addr)).s_addr);
        
	return test_addr.s_addr>=start_addr.s_addr&&test_addr.s_addr<=end_addr.s_addr;
}
