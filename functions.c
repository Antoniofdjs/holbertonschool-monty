#include <stdio.h>
#include "monty.h"


/**
 * clean_up - free and close items used * @line: line from getline file
 * @stack: head of stack_t
 * @file: monty.m file
 */
void clean_up(char *line, stack_t **stack, FILE *file)
{
	free(line);
	if (*stack != NULL)
		free_dlist(stack);
	free(stack);
	fclose(file);
}

/**
 * free_dlist- free previous list int
 *
 *@head: head pointer of nodes
 */

void free_dlist(stack_t **head)
{

	stack_t *temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
