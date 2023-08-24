#include "monty.h"

/**
 * parse - function to parse lines from file
 * @data: line to parse
 */

void parse(char *data)
{
    char *cmd[2];

    cmd[0] = strtok(data, " ");
    cmd[1] = strtok(NULL, " ");
    printf("%s", cmd[0]);
    printf("%s", cmd[1]);
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
		parse(buffer);
	}
	if (buffer != NULL)
	{
		free(buffer);
	}
	fclose(fd);

	return (0);
}
