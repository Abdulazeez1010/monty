#include "monty.h"

/**
 * pint - The opcode pint prints the value at the top of the stack,
 * followed by a new line
 * @stack : The stack
 * @line_number : Current line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	printf("%d\n", current->n);
}
