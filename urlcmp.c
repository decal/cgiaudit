/* Compare URL's while considering index implicitness, something
 * that "Most HTTP servers support", according to RFC2055.
 * code by S <super@udel.edu>
 */

#include<string.h>

static void snip(char*s)
{
	register char*p;

	p=strrchr(s,'/');

	if(p&&p!=strchr(s,'/')+1)
	{
		if(!strncmp(p+1,"index.",6))
			*p=0;
		else
			if(p-s+1==strlen(s))
				*p=0;
	}

	return;

}

int urlcmp(char*s1,char*s2)
{
	if(!strcmp(s1,s2))
	{
		return 0;
	}
	else
	{
		snip(s1);
		snip(s2);
	}

	if(!strcmp(s1,s2))
		return 0;

	return 1;

}
