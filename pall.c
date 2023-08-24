#include "monty.h"

/**
 */
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
