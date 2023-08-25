#include "monty.h"

stack_u *create_node(int num)
{
	stack_u **temp;

	temp = malloc(sizeof(stack_u));
	if(!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	(*temp)->n = num;
	(*temp)->next = NULL;
	(*temp)->prev = NULL;
	return (*temp);
}

/**
 * parse - function to parse lines from file
 * @data: line to parse
 * @line_num: line number
 */

void parse(char *data, unsigned int line_num)
{
	char *cmd[2];
	stack_u **new_node;

	cmd[0] = strtok(data, " ");
	cmd[1] = strtok(NULL, " ");
	printf("%s %s\n", cmd[0], cmd[1]);
	new_node = malloc(sizeof(stack_u));
	if(!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	*new_node = create_node(atoi(cmd[1]));
}

int main(int argc, char *argv[])
{
	FILE *fd;
	char *buffer = NULL;
	int num_line;
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
	if (buffer != NULL)
	{
		free(buffer);
	}
	fclose(fd);

	return (0);
}
