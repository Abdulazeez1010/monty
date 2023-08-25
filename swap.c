#include "monty.h"

/**
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	top->next = second->next;
	if (second->next != NULL)
	{
		second->next->prev = top;
	}
	second->prev = NULL;
	second->next = top;

	top->prev = second;

	*stack = second;
}
