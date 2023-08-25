#include "monty.h"

void pall_action(stack_t **stack, unsigned int line_number){
    int i;
    
    (void) line_number;
    (void) stack;

    if (head)
    {
	    for (i = 0; head != NULL; i++)
	    {
		    printf("%d\n", head->n);
		    head = head->next;
	    }
    }
}
