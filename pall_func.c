#include "monty.h"

/**
 * pall_action - prints all elements in a stack from top
 * @stack: doubly linked list
 * @line_number: line being executed
 */

void pall_action(stack_t **stack, unsigned int line_number)
{
	int i, j;
	stack_t *temp;

	(void) line_number;
	(void) stack;

	printf("hi\n");
	temp = head;
	if (temp)
	{
		for (i = 0; temp->next != NULL; i++)
			temp = temp->next;
		for (j = 0; temp != NULL; j++)
		{
			printf("%d\n", temp->n);
			temp = temp->prev;
		}
	}
}
