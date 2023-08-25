#include "monty.h"
stack_u *head = NULL;

void push_action(stack_t **stack, unsigned int line_number){ 
        stack_t *tmp;

        (void) line_number;

        printf("Push function\n");
        if (head == NULL){
            printf("First push\n");
            head = (*stack);
        }
        else
        {
		    tmp = head;
		    if (tmp->next != NULL){
                while (tmp->next)
		        {
			        tmp = tmp->next;
		        }
            }

		    tmp->next = *stack;
		    (*stack)->prev = tmp;
	    }
}
