/* preprocessor constants */

/* Use this if no explicit Content Length is mentioned by the server. */

#define DEFAULT_CONTENT_LENGTH 65536

/* For urlencode() */
#define HEX_BUF_SIZE 8192

/* maximum length of configuration file entry */
#define CONF_BUF_SIZE 4096

/* Read chunks of HTTP this size. */
#define HTTP_BUF_SIZE 1024

#define DEFAULT_CONFIG_FILE "/usr/local/etc/cgiaudit.conf"

/* macros */

#define SKIP_SPACE(p) while(*p&&isspace(*p))if(*p++=='>')return;

typedef struct URLINFO_def
{
	char*scheme;
	char*host;
	char*user;
	char*pass;
	char*path;
	char*query;
	char*fragment;
	unsigned short port;
}
URLINFO;

typedef struct HTTPCLIINFO_def
{
	long content_length;
	char*method;
	char*enctype;
}
HTTPCLIINFO;

typedef struct HTTPSRVINFO_def
{
	long content_length;
	char code[4];
	char*phrase;
	char*ver;
	char*server;
} 
HTTPSRVINFO;

typedef struct INPUTINFO_def 
{
	char*type;
	char*name;
	char*value;
	char*size;
	char*src;
	char*align;
	unsigned long maxlength;
	unsigned char checked;
}
INPUTINFO;

typedef struct SELECTINFO_def
{
	char*name;
	char*value;
	unsigned long size;
	char multiple;
}
SELECTINFO;

typedef struct TEXTAREAINFO_def
{
	char*name;
	char*value;
	void*next;
	unsigned long cols;
	unsigned long rows;
}
TEXTAREAINFO;

typedef struct FIELDINFO_def
{
	void*field;
	struct FIELDINFO_def*next;
	char type;
}
FIELDINFO;

typedef struct FORMINFO_def
{
	char*name;
	char*url;
	char*action;
	char*method;
	char*enctype;
	FIELDINFO*fieldshead;
	struct FORMINFO_def*next;
	
}
FORMINFO;

typedef struct AINFO_def
{
	char*href;
	struct AINFO_def*next;
}
AINFO;

typedef struct CONFINFO_def
{
	char*ents[4]; /* null terminated array of configuration file entities */
	struct CONFINFO_def*next;
}
CONFINFO;

typedef struct DOCINFO_def
{
	FORMINFO*forminfo;
	AINFO*ainfo;
}
DOCINFO;

typedef struct OPTIONS_def
{
	char*c; /* user-defined configuration file */
	char*s; /* spider netmask */
	char*p; /* proxy hostname */
	unsigned int h; /* help */
	unsigned int v; /* verbosity */
	unsigned int x; /* hexadecimal encoding */
	unsigned int r; /* print http reply/request headers */
	unsigned int t; /* proxy tcp port */
}
OPTIONS;

typedef struct REPORTINFO_def
{
	HTTPSRVINFO httpsrvinfo;
	char*string;
	char*attack;
	FORMINFO*forminfo;
	FIELDINFO*fieldinfo;
	URLINFO*urlinfo;
	struct REPORTINFO_def*next;
}
REPORTINFO;

/* Nested headers. */

#ifndef _STDIO_H
#include<stdio.h>
#endif
#ifndef _SYS_TYPES_H
#include<sys/types.h>
#endif
#ifndef _NETINET_IN_H
#include<netinet/in.h>
#endif
FILE*http_connect(URLINFO*,HTTPSRVINFO*);
DOCINFO*parse_doc(char*,URLINFO*);
URLINFO*parse_url(char*);
CONFINFO*parse_conf(const char*);
int parse_form_field(char**,FIELDINFO*);
char*get_field_value(FIELDINFO*);
char*get_field_name(FIELDINFO*);
void show_doc_info(const HTTPCLIINFO*);
void show_srv_info(const HTTPSRVINFO*);
int cgiaudit(FORMINFO*);
void vexit(const char*);
void bug(const char*);
char*isolate_value(char**);
int parse_input_tag(char**,INPUTINFO*);
int parse_select_tag(char**,SELECTINFO*);
int parse_textarea_tag(char**,TEXTAREAINFO*);
void syntax_error(const char*,const unsigned int);
void discard_tokens_1(char**);
REPORTINFO*cgi_audit(FORMINFO*,URLINFO*);
char*parse_a_tag(char*,AINFO*,URLINFO*);
char*parse_form_tag(char*,FORMINFO*);
FILE*check_tags(FORMINFO*,char*,URLINFO*,HTTPSRVINFO*);
int hexencode(const char*,char*,const int);
int urlcmp(char*,char*);
void report(const REPORTINFO*);

#ifndef _MAIN_C 
extern unsigned int i; /* document */
extern unsigned int n; /* form */
extern int j; /* field */
extern OPTIONS options;
extern CONFINFO*confinfo;
#endif

int setmask(int,struct in_addr*);
int mask(char*);
/* User-Agent: field for HTTP request header */
#define HTTP_USER_AGENT "Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)"
