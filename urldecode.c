#include<ctype.h>
#define HEXDIGIT(c) ((c>='A')?(toupper(c)-'A'+10):(c-'0'))
void urldecode(char *src){
        int     c,lastc=0;
        register unsigned short i=0;
        char    *dst=src;
        while ((c=*src++)!='\0') {
                if(c=='+') c=' ';
                else if (c=='%') {
                        c=HEXDIGIT(*src);
                        src++;
                        c=16 * c + HEXDIGIT(*src);
                        src++;
                        i+=2;
                }
                if ((c!=0x0A) || (lastc!=0x0D)) {
                        if(c=='|'){
                                *dst++='\\';
                                *dst++='|';
                        }
                        else if((c==0x0A)||(c==0x0D)){
                                *dst++='\\';
                                *dst++='n';
                        }
                        else *dst++=c;
                }
                lastc=c;
        }
        *dst++='\0';
}
