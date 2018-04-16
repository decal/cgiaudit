#include<ctype.h>

/*binary to hex conversion*/
static char b2h(char ch){
	ch=ch&0x0f;
	return tolower(((ch+='0')>'9')?ch+=7:ch);
}

int hexencode(const char*plain,char*encode,const int maxlen){
	char ch,*lim,*alpha=encode;

	lim=encode+maxlen-4;
	ch=tolower(*plain++);

	while(ch)
	{
		if(ch==' ')*encode++='+';
		else
		{
			*encode++='%';
            		*encode++=b2h(ch>>4); /*high order nibble*/
            		*encode++=b2h(ch);      /*low order*/
        	}
		/* *encode++=ch; */
        	ch=tolower(*plain++);               
        	if(encode>lim){
            		*encode=0;        
            		return -1;        
        	}
    	}

    	*encode=0;               
    	return encode - alpha;    
}   
