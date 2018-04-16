#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cgiaudit.h"

void ca_putstat(const char*);

extern FIELDINFO*curfield;

FILE*check_tags(FORMINFO*forminfo,char*attackstr,URLINFO*cururl,HTTPSRVINFO*httpsrvinfo)
{
	FILE*so;
	size_t len,origlen,mlen;
	char*absurl,c,*namep=NULL,*ptr,*null;
	FIELDINFO*fieldinfo;
	URLINFO*urlinfo;
	unsigned int url_type=0,action_in_url=0,done=0,current=0;

	/* 
	 * This assumes that index.html is appended for null file fields
	 * and that slashes are always appended to directories.
 	 */

	if(strstr(forminfo->url,forminfo->action)==forminfo->url+strlen(forminfo->url)-strlen(forminfo->action))
	{
		action_in_url=1;
	}

	origlen=strlen(forminfo->url)+strlen(forminfo->action)+2;

	if(strncmp(forminfo->action,"http://",7))
	/* Handle relative paths. */
	{
		if(*(forminfo->action)=='/')
		/* Relative to root directory. */
		{
			origlen+=strlen(cururl->host);
			url_type=1;
		}
		else
		/* Relative to current directory. */
		{
			/* +1 is for seperating forward slash. */
			origlen+=strlen(cururl->host)+strlen(cururl->path)+1;
			url_type=2;
		}
	}

	len=origlen;
		
	/* Compute length of hash pairs. */
	for(
		fieldinfo=forminfo->fieldshead;
		/*fieldinfo&&fieldinfo->next*/
		fieldinfo;
		fieldinfo=fieldinfo->next
	)
	{
		switch(fieldinfo->type)
		{
			case 'i':
				namep=((INPUTINFO*)fieldinfo->field)->name;
				if(((INPUTINFO*)fieldinfo->field)->maxlength)
					mlen=((INPUTINFO*)fieldinfo->field)->maxlength;
				else mlen=128;
				break;
			case 's':
				namep=((SELECTINFO*)fieldinfo->field)->name;
				mlen=128;
				break;
			case 't':
				namep=((TEXTAREAINFO*)fieldinfo->field)->name;
				mlen=128;
				break;
		}

		if(!namep)
			/* Ignore fields with no NAME attribute. */
			continue;

		len+=strlen(namep);
		len++; /* '=' */

		/* trying to overflow here */
		len+=mlen+strlen(attackstr);
		
		len++; /* '&' */
	}

	absurl=malloc(len);
	if(!absurl)
		vexit("malloc");

	namep=strrchr(forminfo->url,'/');
	if(namep)
	{
		if(*(forminfo->action)=='/')
		{
			c=*namep;
			*namep=0;
		}
		else
		{
			c=*(++namep);
			*namep=0;
		}
	}

	ptr=absurl;

	switch(url_type)
	{
		case 0:
			break;
		case 1:
			/* Relative to root. */
			strcpy(absurl,"http://");
			ptr+=7;
			strcpy(ptr,cururl->host);
			ptr+=strlen(cururl->host);
			break;
		case 2:
			/* Relative to current. */
			strcpy(absurl,"http://");
			ptr+=7;
			strcpy(ptr,cururl->host);
			ptr+=strlen(cururl->host);
			strcpy(ptr,cururl->path);
			ptr+=strlen(cururl->path);
			break;
		default:
			bug("Unknown url_type!");
	}

	/* strcpy(ptr,forminfo->url);
	ptr+=strlen(forminfo->url); */

	if(!action_in_url)
	{
		strcpy(ptr,forminfo->action);
		ptr+=strlen(forminfo->action);
	}

	strcpy(ptr,"?");
	ptr+=1;

	null=ptr;

	*namep=c;

	for(
		fieldinfo=forminfo->fieldshead;
		/*fieldinfo&&fieldinfo->next;*/
		fieldinfo;
		fieldinfo=fieldinfo->next,current++
	)
	{

		switch(fieldinfo->type)
		{
			case 'i':
				namep=((INPUTINFO*)fieldinfo->field)->name;
				break;
			case 's':
				namep=((SELECTINFO*)fieldinfo->field)->name;
				break;
			case 't':
				namep=((TEXTAREAINFO*)fieldinfo->field)->name;
				break;
		}

		if(!namep)
			/* Ignore fields with no NAME attribute. */
			continue;

		if(fieldinfo!=forminfo->fieldshead)
			strcat(absurl,"&");

		strcat(absurl,namep);
		strcat(absurl,"=");

		/* Attach the attackstr to only one field. */
		if(current==j)
		{
			curfield=fieldinfo;
			done=1;
			strcat(absurl,attackstr);
		}
		else
		{
			char*val;

			/* 
			 * Fill in a default value if there is any. 
			 * This facilitates normal CGI program execution by providing 
			 * proper input.
			 */

			if((val=get_field_value(fieldinfo)))
				strcat(absurl,val);
			else
				strcat(absurl,"A");
		}
	}

	if(!done)
		return NULL;

	urlinfo=parse_url(absurl);

	if(!urlinfo||!(urlinfo->host))
		return NULL;

	so=http_connect(urlinfo,httpsrvinfo);
	
	if(so)
	{
		const char*msg1="checking ";
		const char*msg2="field .. ";
		const char*noname="nameless ";

		char*s1,*p1;

		switch(curfield->type)
		{
			case 'i':
				namep=((INPUTINFO*)curfield->field)->name;
				break;
			case 's':
				namep=((SELECTINFO*)curfield->field)->name;
				break;
			case 't':
				namep=((TEXTAREAINFO*)curfield->field)->name;
				break;
		}

		s1=malloc(strlen(msg1)+strlen(msg2)+(namep?strlen(namep):strlen(noname))+2);
		if(!s1)
			vexit("malloc");

		if(options.v)
		{

			strcpy(p1=s1,msg1);
			p1+=strlen(msg1);

			if(namep)
			{
				strcpy(p1,namep);
				p1+=strlen(namep);
				*p1=' ';
				p1++;
			}
			else
			{
				strcpy(p1,noname);
				p1+=strlen(noname);
			}

			strcpy(p1,msg2);

			ca_putstat(s1);
		}

	}

	if(options.v)
	{
		if(!options.r)
			show_srv_info(httpsrvinfo);
		else
			putchar('\n');
	}

	/* if(httpsrvinfo->code[0]=='4')
	{
		puts(cururl->host);
		puts(cururl->path);
	} */

	/* if(httpsrvinfo.code[0]=='4')
	{
		puts("\n4xx CLIENT ERROR! :-/\n");
		show_doc_info(&httpcliinfo);
	} */

	if(httpsrvinfo->code[0]=='5')
	{
		puts("\n5xx SERVER ERROR! :-)\n");
		show_srv_info(httpsrvinfo);
	}

	return so;
}
