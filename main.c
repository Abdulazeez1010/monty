#include "monty.h"

/**
 */
int main (int argc, char *argv[])
{
	int found;
	unsigned int line_number;
	ssize_t i;
	char line[256];
	char *token;
	stack_t *stack;
	FILE *file;
	instruction_t instructions[] = 
	{
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}

	stack = NULL;
	line_number = 0;
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		token = strtok(line, " \t\n");
		if (token == NULL)
			continue;
		found = 0;
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(token, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				found = 1;
				break;
			}
		}
		if (!found)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
	return (EXIT_SUCCESS);
}


void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *token;
	int value;

	token = strtok(NULL, " ");
	if (token == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(token);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node -> n = value;
	new_node -> prev = NULL;
	new_node -> next = NULL;
	if (*stack != NULL)
	{
		new_node -> next = *stack;
		(*stack) -> prev = new_node;
	}
	*stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *temp;
	(void) line_number;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current -> n);
		temp = current;
		current = current -> next;
		free(temp);
	}
}
