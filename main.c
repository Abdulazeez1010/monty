#include "monty.h"

/**
 */
int main (int argc, char *argv[])
{
	int file_descriptor, in_word, line_number, value;
	ssize_t bytes_read, i;
	char buffer[100];
	char current_line[124];
	char *token;
	ssize_t current_line_len = 0;
	stack_t *stack;
	instruction_t instructions[] = 
	{
		{"push", push},
		{"pall", pall}
	};

	stack = NULL;
	if (argc != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		perror("Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}

	in_word = 1;
	while ((bytes_read = read(file_descriptor, buffer, sizeof(buffer))) > 0)
	{
		line_number = 1;
		for (i = 0; i < bytes_read; i++)
		{
			if (buffer[i] == '\n')
			{
				current_line[current_line_len++] = '\0';
				if (in_word)
				{
					token = strtok(current_line, " ");
					if (token != NULL && strcmp(token, "push") == 0)
					{
						token = strtok(NULL, " ");
						value = atoi(token);
						if (token != NULL)
						{
							instructions[0].f(&stack, line_number, value);
						}
						else
						{
							fprintf(stderr, "L%d: usage: push integer\n", line_number);
						}
					}
					else if (token != NULL && strcmp(token, "pall") == 0)
						instructions[1].f(&stack, line_number, value);
					else
					{

						fprintf(stderr, "L%d: unknown instruction %s\n", line_number, current_line);
						close(file_descriptor);
						exit(EXIT_FAILURE);
					}
				}
				current_line_len = 0;
				line_number++;
				in_word = 0;
			}
			else
			{
				current_line[current_line_len++] = buffer[i];
				if (buffer[i] != ' ' && buffer[i] != '\t')
					in_word = 1;
			}
		}
	}
	if (bytes_read == -1)
	{
		exit(EXIT_FAILURE);
	}

	close(file_descriptor);
	return (0);
}


void push(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node -> n = value;
	new_node -> prev = NULL;
	new_node -> next = *stack;
	if (*stack != NULL)
		(*stack) -> prev = new_node;
	*stack = new_node;

	line_number++;
}

void pall(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *current;
	(void) value;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current -> n);
		current = current -> next;
	}

	line_number++;
}
