#include "monty.h"

/**
 * t4_add - adds the top two elements of the stack.
 * @head: double pointer
 * @c: int
 */
void t4_add(stack_t **head, unsigned int c)
{
	stack_t *head0;
	int a;

	m_function(*head, c, "can't add, stack too short", 1);
	head0 = *head;
	a = head0->n + head0->next->n;
	head0->next->n = a;
	*head = head0->next;
	free(head0);
}

/**
 *t5_nop - doesn’t do anything.
 *@head: pointer
 *@c: int
 */
void t5_nop(stack_t **head, unsigned int c)
{
	(void) c;
	(void) head;
}

/**
 *t6_sub -  subtracts the top element of the stack from the second
 *@head: pointer
 *@c: int
 */
void t6_sub(stack_t **head, unsigned int c)
{
	stack_t *head0;
	int res;

	m_function(*head, c, "can't sub, stack too short", 1);
	head0 = *head;
	res = head0->next->n - head0->n;
	head0->next->n = res;
	*head = head0->next;
	free(head0);
}
