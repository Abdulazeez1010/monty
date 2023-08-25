#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;
	second->n = second->n + top->n;
	second->prev = NULL;
	*stack = second;
}
