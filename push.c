#include "monty.h"

/**
 */
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
