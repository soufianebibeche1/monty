#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
