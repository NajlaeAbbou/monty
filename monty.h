#ifndef MONTY
#define MONTY

#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - args, file, content
 * @arg: char
 * @file: monty file
 * @content: content
 * @lifi: queue
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;
extern bus_t bus;


/* functions */

void t0_push(stack_t **head, unsigned int c);
void t0_pall(stack_t **head, unsigned int c);
void add_node(stack_t **head, int n);
void add_queue(stack_t **head, int n);
void m_freestack(stack_t *head);
int m_executefunct(char *content, stack_t **stack, unsigned int c, FILE *file);
void m_function(stack_t *head, unsigned int c, char *message, int flag);
void t1_pint(stack_t **head, unsigned int c);
void t2_pop(stack_t **head, unsigned int c);
void t3_swap(stack_t **head, unsigned int c);
void t4_add(stack_t **head, unsigned int c);
void t5_nop(stack_t **head, unsigned int c);
void t6_sub(stack_t **head, unsigned int c);
void t7_div(stack_t **head, unsigned int c);
void t8_mul(stack_t **head, unsigned int c);
void t11_pchar(stack_t **head, unsigned int c);
void t12_pstr(stack_t **head, unsigned int c);
void t13_rotl(stack_t **head, unsigned int c);
void t14_rotr(stack_t **head, unsigned int c);
void t15_stack(stack_t **head, unsigned int c);
void t15_queue(stack_t **head, unsigned int c);
void t9_mod(stack_t **head, unsigned int c);

#endif
