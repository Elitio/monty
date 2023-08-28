#include "monty.h"

/**
 * pint_action - prints the top of a stack
 * @stack: node
 * @line_number: number of line being executed
 */

void pint_action(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int i;

	(void) stack;
	temp = head;

	if (!temp)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; temp->next != NULL; i++)
	{
		temp = temp->next;
	}
	printf("%d\n", temp->n);
}
