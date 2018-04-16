#include"cgiaudit.h"
char*get_field_name(FIELDINFO*fieldinfo)
{
	if(fieldinfo)
		switch(fieldinfo->type)
		{
			case 'i':
				return ((INPUTINFO*)fieldinfo->field)->name;
			case 's':
				return ((SELECTINFO*)fieldinfo->field)->name;
			case 't':
				return ((TEXTAREAINFO*)fieldinfo->field)->name;
			default:
				bug("Unknown form field type!");
		}

	return NULL;
}
