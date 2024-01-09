#include "monty.h"

/**
 * mod - devide n2/n1 save at n2, pop after
 * @stack: head of stack_t list
 * @line_number: number of line from file
 * @line: line from fgets from file
 * @file: monty.m file
 */

void mod(stack_t **stack, unsigned int line_number, char *line, FILE *file)
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
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
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
	temp->n = ((temp->n) % (temp_n)); /*sub is done at node temp2 n2 -n1 */
	pop(stack, line_number, line, file); /* remove the first node */
}

