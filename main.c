#include "monty.h"
stack_t *head = NULL;

/**
 * create_node - function to create a node
 * @num: value to insert in node
 * Return: stack_t
 */

stack_t *create_node(int num)
{
	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp->n = num;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

/**
 * stack_func - function to execute opcodes
 * @node: node to add to stack
 * @type: array of strings containing args
 * @count: number of line from file being executed
 */

void stack_func(stack_t **node, char **type, unsigned int count)
{
	int i;
	bool check = false;
	instruction_t actions[] = {
		{"push", push_action}, {"pall", pall_action},
		{"pint", pint_action}
	};

	i = 0;
	while (actions[i].opcode)
	{
		if (strcmp(actions[i].opcode, type[0]) == 0)
		{
			actions[i].f(node, count);
			check = true;
			break;
		}
		i++;
		if (i >= 3)
			break;
	}
	if (check == false)
	{
		printf("L%d: unknown instruction %s\n", count, type[0]);
		exit(EXIT_FAILURE);
	}
}

/**
 * parse - function to parse command
 * @data: the line from file to parse
 * @line_num: number of line in file being parsed
 */

void parse(char *data, unsigned int line_num)
{
	char *cmd[2];
	stack_t **new_node = NULL;

	cmd[0] = strtok(data, " ");
	cmd[1] = strtok(NULL, " ");

	if (cmd[1])
	{
		new_node = malloc(sizeof(stack_t));
		if (!new_node)
		{
			dprintf(2, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		(*new_node) = create_node(atoi(cmd[1]));
	}
	else if (strcmp(cmd[0], "push") == 0)
	{
		printf("L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	stack_func(new_node, cmd, line_num);
}

/**
 * main - Entry point
 * @argc: number of args
 * @argv: array of string
 * Return: 0 if success
 */

int main(int argc, char *argv[])
{
	FILE *fd;
	char *buffer = NULL;
	unsigned int num_line;
	size_t n;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (num_line = 1; getline(&buffer, &n, fd) != EOF; num_line++)
	{
		parse(buffer, num_line);
	}
	free(buffer);
	return (0);
}
