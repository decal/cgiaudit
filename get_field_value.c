#include"cgiaudit.h"
char*get_field_value(FIELDINFO*fieldinfo)
{

	char*ret=NULL;

	if(fieldinfo)
		switch(fieldinfo->type)
		{
			case 'i':
				ret=((INPUTINFO*)fieldinfo->field)->value;
				break;
			case 's':
				ret=((SELECTINFO*)fieldinfo->field)->value;
				break;
			case 't':
				ret=((TEXTAREAINFO*)fieldinfo->field)->value;
				break;
			default:
				bug("Unknown form field type!");
		}

	return ret;
}
