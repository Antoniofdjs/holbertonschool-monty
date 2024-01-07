#include <stdio.h>
#include "monty.h"


/**
 * clean_up - free and close items used * @line: line from getline file
 * @stack: head of stack_t
 * @file: monty.m file
 * @line: read line from file
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

/**
 * ops_exe - Takes line from file to execute commands read
 * @stack: head of list from stack_t
 * @line_number: line number of the file
 * @line: string from lines
 * @file: file set as upstream of getline
 */

void ops_exe(stack_t **stack, char *line, unsigned int line_number, FILE *file)
{

	char *opcode = NULL;
	int i;

	instruction_t instructions[] = {{"push", push}, {"pall", pall}, {"pop", pop},
		{"add", add}, {"sub", sub}, {"_div", _div}, {"nop", nop}, {"pint", pint},
		{"swap", swap}, {NULL, NULL}
	};

	opcode = strtok(line, " ");
	for (i = 0; instructions[i].f != NULL && opcode != NULL; i++)/*calls*/
	{
		if (strcmp(instructions[i].opcode, opcode) == 0) /* Matched a case */
		{
			instructions[i].f(stack, line_number, line, file);
			break;
		}
	}
	if (instructions[i].f == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		clean_up(line, stack, file);
		exit(EXIT_FAILURE);
	}
}
