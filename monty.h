#ifndef MONTY_H
#define MONTY_H
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO??
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number, char *line, FILE *file);
} instruction_t;
void clean_up(char *line, stack_t **stack, FILE *file);
void ops_exe(stack_t **stack, char *line, unsigned int line_number, FILE *file);
void push(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void pall(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void free_dlist(stack_t **head);
void pop(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void swap(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void pint(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void nop(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void _div(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void mul(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void mod(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void add(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void sub(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void nop(stack_t **stack, unsigned int line_number, char *line, FILE *file);
#endif /* MONTY_H */
