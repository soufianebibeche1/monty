#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* Define the struct for the stack element */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/* Define the struct for the Monty instruction */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes for Monty opcodes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/* Add any additional function prototypes here */
instruction_t *get_instruction(char *opcode);
void free_stack(stack_t **stack);
int is_numeric(char *str);
instruction_t *get_instruction(char *opcode);
void push_stack(stack_t **stack, int value);

#endif /* MONTY_H */
