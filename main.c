/* super's cgiaudit */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define _MAIN_C 1
#include"cgiaudit.h"

static void usage(char*[]);

unsigned int i=1;
unsigned int n;
int j=-1;

OPTIONS options;
CONFINFO*confinfo;

int main(int argc,char*argv[])
{
	FORMINFO*forminfo;
	URLINFO **urlinfo;
	DOCINFO*docinfo=NULL;
	AINFO*my_ainfo=NULL,*ptr_ainfo,*ind_ainfo,*done_ainfo=NULL;
	REPORTINFO*reportinfo=NULL,*cur,*ret;
	unsigned char x1=1;
	int my_argc=argc;
	int c;
	char**my_argv=argv;

	puts("\ncgiaudit by S");
	puts("~^~^~^~^~^~^~\n");

	if(argc<2)
		usage(argv);

	while((c=getopt(argc,argv,"hvxrc:s:p:t:"))!=EOF)
	{
		switch (c)
		{
			case 'c':
				options.c=optarg;
				break;
			case 's': /* spider */
				options.s=optarg;
				if(options.s[0]=='/')
					options.s=&(options.s[1]);
				break;
			case 'v': /* verbosity */
				options.v++;
				break;
			case 'x': /* hex encoding of requests */
				options.x++;
				break;
			case 'p': /* proxy hostname */
				options.p=optarg;
				break;
			case 'r': /* print http request/reply headers */
				options.r++;
				break;
			case 't': /* proxy tcp port */
				options.t=atoi(optarg);
				break;
			case 'h': /* help */
			case '?':
			default:
				usage(argv);
		}
	}

	if((options.p&&!options.t)||(options.t&&!options.p))
		usage(argv);

	confinfo=parse_conf(options.c?options.c:DEFAULT_CONFIG_FILE);

	/* 
	 * Audit each form that is part of the document(s) supplied on the 
	 * on the command-line. Obviously, subtract 1 from argc in order to
	 * compensate for the command name.
	 */

	urlinfo=calloc((size_t)(my_argc),sizeof(*urlinfo));
	if(!urlinfo)
		vexit("malloc");

	if(optind==my_argc)
		usage(argv);

	do 
	{
		for(;optind<my_argc;optind++,i++)
		{
			urlinfo[optind]=parse_url(my_argv[optind]);
			if(!urlinfo[optind])
			{
				putchar('\n');
				printf("[%d.%d] Invalid URL (did you include \"http://\"?)\n",i,n);
				break;
			}
			/* docinfo will be NULL on first iteration, before setmask() */

			if(docinfo&&options.s)
			{
				/* Don't follow referenced documents outside of our netblock. */
				if(!mask(urlinfo[optind]->host))
				{
					if(!done_ainfo)
					{
						done_ainfo=calloc(1,sizeof(*done_ainfo));
						if(!done_ainfo)
							vexit("calloc");
						done_ainfo->href=malloc(strlen(my_argv[1])+1);
						if(!done_ainfo->href)
							vexit("malloc");
						strcpy(done_ainfo->href,my_argv[1]);
						ind_ainfo=done_ainfo;
					}
					else
					{
						ind_ainfo->next=calloc(1,sizeof(*(ind_ainfo->next)));
						if(!(ind_ainfo->next))
							vexit("calloc");
						ind_ainfo=ind_ainfo->next;
						ind_ainfo->href=malloc(strlen(my_argv[1])+1);
						if(!ind_ainfo->href)
							vexit("malloc");
						strcpy(ind_ainfo->href,my_argv[1]);
					}
					continue;
				}
			}

			printf("[%d.%d] Parsing document %s .. ",i,n,my_argv[optind]);
			if(options.r)
				putchar('\n');
			docinfo=parse_doc(my_argv[optind],urlinfo[optind]);

			if(!docinfo)
				continue;

			/* Accumlate the entire set of ainfo lists returned
			 * by parse_doc()
			 */
			if(!my_ainfo)
			{
				my_ainfo=docinfo->ainfo;
			}
			else
			{
				for(ptr_ainfo=my_ainfo;ptr_ainfo->next;ptr_ainfo=ptr_ainfo->next);
				ptr_ainfo->next=docinfo->ainfo;
			}

			forminfo=docinfo->forminfo;
			if(forminfo)
			{
				n=1;
				printf("[%d.0] Done parsing HTML; commencing audit routine.\n",i);
				do
				{
					if(forminfo->fieldshead&&forminfo->action)
					{
						printf("[%d.%d] Now auditing form %d ",i,n,n);
						fputs(forminfo->name?forminfo->name:"null",stdout);
						putchar('\n');

						ret=cgi_audit(forminfo,urlinfo[optind]);
						if(ret)
						{
							if(reportinfo)
							{
								cur->next=ret;
								cur=cur->next;
							}
							else
							{
								reportinfo=ret;
							}
						}
					}
					else
					{
						if(options.v)
							printf("[%d.%d] Form %d (%s) is empty!\n",i,n,n,forminfo->name?forminfo->name:"unnamed");
					}

					forminfo=forminfo->next;
					n++;
				} while(forminfo);

				printf("[%d.0] Done with this document!\n",i);
			}
			else
			{
				printf("[%d.0] No forms found while parsing this document!\n",i);
			}

			/* maintain a list of spidered url's so there
			* may be no repeat audits. */

			if(!done_ainfo)
			{
				done_ainfo=calloc(1,sizeof(*done_ainfo));
				if(!done_ainfo)
					vexit("calloc");
				done_ainfo->href=malloc(strlen(my_argv[1])+1);
				if(!done_ainfo->href)
					vexit("malloc");
				strcpy(done_ainfo->href,my_argv[1]);
				ind_ainfo=done_ainfo;
			}
			else
			{
				ind_ainfo->next=calloc(1,sizeof(*(ind_ainfo->next)));
				if(!(ind_ainfo->next))
					vexit("calloc");
				ind_ainfo=ind_ainfo->next;
				ind_ainfo->href=malloc(strlen(my_argv[1])+1);
				if(!ind_ainfo->href)
					vexit("malloc");
				strcpy(ind_ainfo->href,my_argv[1]);
			}
		} /* for(;i<my_argc;i++) */

		if(!options.s)
			/* Done if not spidering. */
			break;

		optind=1;
		my_argc=2;
		if(x1==1)
			my_argv=malloc(sizeof(*my_argv)*++x1);
		/* Done processing command-line arguments, check
		 * referenced documents (if spidering). */

		if(my_ainfo)
		{
			while(!my_ainfo->href&&(my_ainfo=my_ainfo->next));

			if(!my_ainfo)
				break;

			ptr_ainfo=done_ainfo;

			while(1)
			{
				do 
					if(!urlcmp(ptr_ainfo->href,my_ainfo->href))
					{
						my_ainfo=my_ainfo->next;
						if(!my_ainfo)
							break;
						while(!my_ainfo->href&&(my_ainfo=my_ainfo->next));
						if(!my_ainfo)
							break;

						ptr_ainfo=done_ainfo;
						break;
					}
				while((ptr_ainfo=ptr_ainfo->next));

				if(ptr_ainfo&&my_ainfo)
					continue;

				break;
			}

			if(!my_ainfo)
				break;

			my_argv[1]=my_ainfo->href;
		}

		if(!my_ainfo||!my_argv[1])
			break;

	} while(1);

	report(reportinfo);
	
	exit(EXIT_SUCCESS);
}

static void usage(char*argv[])
{
	printf("usage: %s [-hrvx] [-s bits] [-p proxyhost -t proxy port] [-c file] URL [URL2] [...]\n",argv[0]);
	puts("-h          help");
	puts("-c file     config file");
	puts("-p hostname proxy host");
	puts("-r          print headers"); 
	puts("-s [#|/#]   spider");
	puts("-t port     proxy port");
	puts("-v          verbose");
	puts("-x          hex urlencode");

	putchar('\n');
	exit(EXIT_SUCCESS);
}

/*immediately*/
