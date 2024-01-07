#include "monty.h"

/**
 * sub - substract n1 from n2, save at n2, pop after
 *
 * @stack: head of stack_t list
 * @line_number: number of line from file
 * @line: line from fgets from file
 * @file: monty.m file
 */

void sub(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	int total_nodes = 0, temp_n = 0;
	stack_t *temp = NULL;

	temp = *stack;
	while (temp != NULL && *stack != NULL)
	{
		total_nodes++;
		temp = temp->next;
	}
	if (total_nodes < 2 || stack == NULL) /* less than 2 nodes, cant add them */
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		clean_up(line, stack, file);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	temp_n = temp->n; /* value of first node stored in temp_n */
	temp = temp->next; /* next node */
	temp->n = ((temp->n) - (temp_n)); /*sub is done at node temp2 n2 -n1 */
	pop(stack, line_number, line, file); /* remove the first node */
}

/**

 * _div - devide n2/n1 save at n2, pop after
 * @stack: head of stack_t list
 * @line_number: number of line from file
 * @line: line from fgets from file
 * @file: monty.m file
 */

void _div(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	int total_nodes = 0, temp_n = 0;
	stack_t *temp = NULL;

	temp = *stack;
	while (temp != NULL && *stack != NULL)
	{
		total_nodes++;
		temp = temp->next;
	}
	if (total_nodes < 2 || stack == NULL) /* less than 2 nodes*/
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		clean_up(line, stack, file);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		clean_up(line, stack, file);
		exit(EXIT_FAILURE);
	}
	temp_n = temp->n; /* value of first node stored in temp_n */
	temp = temp->next; /* next node */
	temp->n = ((temp->n) / (temp_n)); /*sub is done at node temp2 n2 -n1 */
	pop(stack, line_number, line, file); /* remove the first node */
}

/**
 *pint - function that print the value at the top of stack
 *@stack: double pointer to head of the stack
 *@line_number: the number of the line in file
 *@line: line read from file
 *@file: file that contains read from monty.m file
 */
void pint(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	(void)line;
	(void)file;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 *nop - doesn't do anything
 *@stack: list
 *@line_number: line number in the file
 *@line: string
 *@file: file set as upstream of getline
 */
void nop(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	(void) stack;
	(void) line_number;
	(void) line;
	(void) file;
}
