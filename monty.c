#include <stdio.h>
#include "monty.h"

/**
 * white_spaces - checks if args is null, has only white spaces
 * @args: array from get_tokens, from main
 * @line_number: string from main, from stdin
 * Return: 0 if args was null(white spaces only)
 */
int white_spaces(char **args, unsigned int line_number)
{
	if (args[0] == NULL) /* white spaces only */
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_number, args[0]);
		free(args);
		return (0);
	}
	return (-1);
}
/**
 * arg_validation - validate user input argv
 */
void arg_validation(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE); }

	/**
	 * main - monty translator * @argc: argument count
	 * @argv: argument content
	 * Return: 0
	 */
int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	char *line = NULL;
	size_t len = 0, i;
	FILE *file;
	char *opcode;

	stack_t **stack;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	if (argc != 2 || argv[1] == NULL)
		arg_validation();
	stack = malloc(sizeof(stack_t *));
	*stack = NULL;
	file = fopen(argv[1], "r");/* read monty.m file */
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(stack);
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, file) != EOF)) /* Line by line copy into line */
	{
		line_number++;
		line[strlen(line) - 1] = '\0'; /* remove \n from the end of line */

		opcode = strtok(line, " ");
		if(opcode != NULL)
		{
			for (i = 0; instructions[i].f != NULL; i++) /*Still have functions to call*/
			{
				if (strcmp(instructions[i].opcode, opcode) == 0) /* Matched a case */
				{
					instructions[i].f(stack, line_number);
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
	}
	clean_up(line, stack, file);
	return (0);
}
