#include "monty.h"


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
