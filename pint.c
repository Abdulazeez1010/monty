#include "monty.h"

/**
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty", line_number);
		exit (EXIT_FAILURE);
	}

	current = *stack;
	printf("%d\n", current -> n);
}
