#include<stdlib.h>
#include<assert.h>
#include"cgiaudit.h"

/* Parse HTML field tags that are contained by a form.
 * @param p2 current position of pointer in character buffer
 * @param fieldinfo store information about the form here
 */
int parse_form_field(char**p2,FIELDINFO*fieldinfo)
{
	switch(fieldinfo->type)
	{
		case 'i':
			fieldinfo->field=calloc(1,sizeof(INPUTINFO));
			if(!fieldinfo->field)
				vexit("calloc");

			parse_input_tag(p2,fieldinfo->field);
			break;
		case 's':
			fieldinfo->field=calloc(1,sizeof(SELECTINFO));
			if(!fieldinfo->field)
				vexit("calloc");

			parse_select_tag(p2,fieldinfo->field);
			break;
		case 't':
			fieldinfo->field=calloc(1,sizeof(TEXTAREAINFO));
			if(!fieldinfo->field)
				vexit("calloc");

			parse_textarea_tag(p2,fieldinfo->field);
			break;
		default:
			assert(fieldinfo->type||!fieldinfo->type);
			exit(EXIT_FAILURE);
	}

	return 0;
}
