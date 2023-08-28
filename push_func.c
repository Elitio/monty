#include "monty.h"

/**
 * push_action - adds an element to a stack
 * @stack: node to add
 * @line_number: line number being executed
 */

void push_action(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (head == NULL)
	{
		head = (*stack);
	}
	else
	{
		tmp = head;
		if (tmp->next != NULL)
		{
			while (tmp->next)
			{
				tmp = tmp->next;
			}
		}

		tmp->next = *stack;
		(*stack)->prev = tmp;
	}
}
