#include "monty.h"

/**
 * free_stack - Frees all nodes in a stack_t doubly linked list
 * @stack: Double pointer to the head of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *current, *temp;

	current = *stack;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}
