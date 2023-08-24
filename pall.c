#include "monty.h"

/**
 * pall - The opcode pall prints all the values on the stack,
 * starting from the top of the stack
 * @stack : The stack
 * @line_number : Current line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *temp;
	(void) line_number;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		temp = current;
		current = current->next;
		free(temp);
	}
}
