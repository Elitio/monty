#include "monty.h"

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
	fd = open(argv[1], O_RDONLY);
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (num_line = 1; getline(&buffer, &n, fd) != EOF; num_line++)
	{
		printf("%s\n", buffer);
	}
	if (buffer != NULL)
	{
		free(buffer);
	}
	close(fd);

	return (0);
}
