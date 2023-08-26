#include "monty.h"

stack_t *create_node(int num){
    stack_t *temp;

    temp = malloc(sizeof(stack_t));
    if(!temp)
    {
            dprintf(2, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
    }

    temp->n = num;
    temp->next = NULL;
    temp->prev = NULL;
    return (temp);
}

void stack_func(char **type, unsigned int count)
{
    int i;
    stack_t **new_node;
    instruction_t actions[] = {
        {"push", push_action}, {"pall", pall_action}
    };

    if (type[1])
    {
	    new_node = malloc(sizeof(stack_t));
	    if(!new_node)
	    {
            dprintf(2, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
	    }
    (*new_node) = create_node(atoi(type[1]));
    }
    else if (strcmp(type[0], "push") == 0)
    {
	    printf("L%d: Usage: push integer\n", count);
	    exit(EXIT_FAILURE);
    }

    i = 0;

    while (actions[i].opcode)
    {
        if (strcmp(actions[i].opcode, type[0]) == 0)
        {
            actions[i].f(new_node, count);
	    break;
        }
	i++;
    }
}

void parse(char *data, unsigned int line_num)
{
    char *cmd[2];

    cmd[0] = strtok(data, " ");
    cmd[1] = strtok(NULL, " ");
    stack_func(cmd, line_num);
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
        free(buffer);        
        return (0);
}

