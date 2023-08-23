#include "monty.h"

/**
 * if_number - Checks for a number.
 *
 * @s: The string to be checked.
 * Return: Returns 1 if success, -1 if fails.
 */

int if_number(char *s)
{
	int count = 0;

	while (s[count])
	{
		if (!(isdigit(s[count])))
		{
			return (-1)
		}
		count++;
	}
	return (1);
}

/**
 * push - The opcode pushes an element to stack.
 *
 * @stack - pointer to the pointer to stack.
 * @given_num - The number passed to the stack as element.
 * Return: Returns void
 */

void push(stack_t **stack, unsigned int given_num)
{
	stack_t *1_node;
	int status;

	1_node = malloc(sizeof(stack_t));
	if(!1_node)
	{
		dprintf(2, "Error: malloc failed\n", given_num);
		exite(EXIT_FAILURE);
	}
	status = atoi(monty.arg);
	1_node->n = status;
	1_node->next = NULL;
	1_node->prev = NULL;

	if (!(*stack))
	{
		(*stack) = 1_node;
		return;
	}
	1_node->next = (*stack);
	(*stack)->prev = 1_node;
	(*stack) = 1_node;
}
