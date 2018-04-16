#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<signal.h>
#include<sys/fcntl.h>
#include"cgiaudit.h"

/* 
 * Parse an HTML 3.2 Reference Specification document. 
 * @author Derek Callaway <super@udel.edu> -- S@IRC
 * @param url An HTTP reference to a document to parse. 
 * @see http://www.w3.org/TR/REC-html32.html
 * 
 * Note: This is the root function of a recursive descent parser.
 */

static void handler(int);

/* thread unsafe new field */
static void tu_new_field(FORMINFO*formcurrent,char**p,const char type)
{
	size_t chunk;

	FIELDINFO*fieldcurrentp;

	if(formcurrent->fieldshead)
	{
		fieldcurrentp=formcurrent->fieldshead;
		for(;fieldcurrentp&&fieldcurrentp->next;fieldcurrentp=fieldcurrentp->next); 
		fieldcurrentp->next=calloc(1,sizeof(*(fieldcurrentp->next)));
		if(!fieldcurrentp->next)
			vexit("calloc");
		fieldcurrentp=fieldcurrentp->next;
	}
	else
	{
		formcurrent->fieldshead=calloc(1,sizeof(*(formcurrent->fieldshead)));
		if(!formcurrent->fieldshead)
			vexit("calloc");
		fieldcurrentp=formcurrent->fieldshead;
	}

	switch(type)
	{
		case 'i':
			chunk=sizeof(INPUTINFO);
			break;
		case 's':
			chunk=sizeof(SELECTINFO);
			break;
		case 't':
			chunk=sizeof(TEXTAREAINFO);
			break;
		default:
			bug("Unknown form field type!");
	}

	fieldcurrentp->field=malloc(chunk);
	if(!fieldcurrentp->field)
		vexit("malloc");

	fieldcurrentp->type=type;

	while(**p&&isspace(**p))
		++*p;

	parse_form_field(p,fieldcurrentp);

	return;
}

DOCINFO*parse_doc(char*url,URLINFO*cururl)
{
	DOCINFO*docinfo;
	FORMINFO*forminfo=NULL,*formcurrent=NULL;
	AINFO*ainfo=NULL,*acurrent=NULL,*ahead=NULL;
	FILE*sop;
	char*buf;
	char*p;
	size_t len;
	HTTPSRVINFO httpsrvinfo;

	memset(&httpsrvinfo,0,sizeof(httpsrvinfo));

	/* Remember, http_connect handles 3xx redirects (rfc2068) gracefully. */
	sop=http_connect(cururl,&httpsrvinfo);
	if(!sop)
		return NULL;

	/* if((buf=get_new_url()))
		url=buf; */

	if(!options.r)
		show_srv_info(&httpsrvinfo);

	if(!httpsrvinfo.content_length)
	{
		fprintf(stderr,"[%d.0] WARNING: No Content-Length received from server, implying %d (the entire document may not be parsed)!\n",i,DEFAULT_CONTENT_LENGTH);
		/* I'll just allocate a predefined buffer size in this case. */
		httpsrvinfo.content_length=DEFAULT_CONTENT_LENGTH;
	}
	buf=malloc(httpsrvinfo.content_length+1);
	if(!buf)
		vexit("malloc");
		
	/* 
	 * Interrupt the fread() if the Content Length is invalid or the 
         * bitstream is being received too slow.
	 */

	signal(SIGALRM,handler);
	alarm(30);
	fread(buf,httpsrvinfo.content_length,1,sop);
	if(httpsrvinfo.content_length!=DEFAULT_CONTENT_LENGTH&&strlen(buf)!=httpsrvinfo.content_length)
		fprintf(stderr,"[%d.0] WARNING: Content Length unequal to number of bytes read: Content-Length: %ld, bytes read: %d\n",i,httpsrvinfo.content_length,(int)len);

	for(len=0,p=buf;*p;p++)
	{
		while(*p&&*p!='<')
			p++;

		if(!*p)
			break;

		/* If not inside a form */

		if(!len)
		{
			if(options.s&&!strncasecmp(p,"<A ",3))
			{
				if(!ainfo)
				{
					acurrent=calloc(1,sizeof(*acurrent));
					if(!acurrent)
						vexit("calloc");
					ahead=ainfo=acurrent;
				}
				else
				{
					if(acurrent->href)
					{
						acurrent->next=calloc(1,sizeof(*ainfo));
						if(!acurrent->next)
							vexit("calloc");
						acurrent=acurrent->next;
					}
				}

				p+=3;
				p=parse_a_tag(p,acurrent,cururl);
			}
			if(!strncasecmp(p,"<FORM ",6))
			{
				if(!forminfo)
				{
					formcurrent=calloc(1,sizeof(*forminfo));
					if(!formcurrent)
						vexit("calloc");
					forminfo=formcurrent;
				}
				else
				{
					formcurrent->next=calloc(1,sizeof(*forminfo));
					if(!formcurrent->next)
						vexit("calloc");
					
					formcurrent=formcurrent->next;
				}
				
				/* What URL is this form a part of? */
				formcurrent->url=(char*)url;
				/* Move one past the strlen() of 
				 * of strncmp()'s second argument.
				 */ 
				p+=6;
				len=1;
				p=parse_form_tag(p,formcurrent);
				if(!formcurrent->action)
				{
					/* if(forminfo->next)
					{	
						for(formcurrent=forminfo;formcurrent->next&&formcurrent->next->next;formcurrent=formcurrent->next);
						free(formcurrent->next);
						formcurrent->next=NULL;
					}
					else
					{
						free(forminfo);
						forminfo=NULL;
					} */
				}
			}
		} /* if(!len) */
		else 
		{
			if(!strncasecmp(p,"<INPUT ",7)&&formcurrent)
			{
				/* Advance pointer past matched text */
				p+=7;
				tu_new_field(formcurrent,&p,'i');
			}	

			if(!strncasecmp(p,"<SELECT ",8)&&formcurrent)
			{
				/* Move pointer past token */
				p+=8;
				tu_new_field(formcurrent,&p,'s');
			}
			if(!strncasecmp(p,"<TEXTAREA ",10)&&formcurrent)
			{
				p+=10;
				tu_new_field(formcurrent,&p,'t');
			}
			if(!strncasecmp(p,"</FORM>",7))
			{
				p+=7;
				len=0;
			}
		}
	}

	docinfo=calloc(1,sizeof(*docinfo));
	if(!docinfo)
		vexit("calloc");

	docinfo->forminfo=forminfo;
	docinfo->ainfo=ainfo;

	return docinfo;
}

static void handler(int x)
{
}
