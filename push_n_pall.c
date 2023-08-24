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
			return (-1);
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
	stack_t *node_1;
	int status;

	node_1 = malloc(sizeof(stack_t));
	if(!node_1)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	status = atoi(monty.arg);
	node_1->n = status;
	node_1->next = NULL;
	node_1->prev = NULL;

	if (!(*stack))
	{
		(*stack) = node_1;
		return;
	}
	node_1->next = (*stack);
	(*stack)->prev = node_1;
	(*stack) = node_1;
}

/**
 * print_pall - Will print all the values on the stack, starting from the top
 *
 * @stack: Pointer to the pointer of the stack.
 * @given_num: The number passed to the element of the stack.
 * Return: Will return void.
 */

void pall(stack_t **stack, unsigned int  given_num)
{
	stack_t *tmp;
	(void) given_num;

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
