#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern int value;
char *read_textfile(const char* file, size_t chars);
char **tokenize(char *fb);
void add_dstack_list(stack_t **stack, unsigned int line_number);
void pall_dstack_list(stack_t **stack, unsigned int line_number);
/*get_opcode*/
void execute_line(char *s, stack_t **stack, unsigned int line_number);
void (*get_opcode(char *s))(stack_t **, unsigned int);
/*pint.c*/
void pint_monty(stack_t **stack, unsigned int line_number);
/*free.c*/
void free_stack(stack_t *head);
void free_av(char **line_av);
void free_all(char *tok, char *line);
/*error.c*/
void print_error_usage(unsigned int line_number);
/*exe_monty.c*/
void exe_monty(char **av_line);
#endif
