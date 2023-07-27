#include "monty.h"

/**
 *t14_rotr- rotates the stack to the bottom
 *@head: double pointer
 *@c: int
 */
void t14_rotr(stack_t **head, unsigned int c)
{
	stack_t *head0;
	(void)c;

	head0 = *head;
	if (head0 == NULL || head0->next == NULL)
	{
		return;
	}
	while (head0->next)
	{
		head0 = head0->next;
	}
	head0->next = *head;
	head0->prev->next = NULL;
	head0->prev = NULL;
	(*head)->prev = head0;
	(*head) = head0;
}

/**
 * t15_stack - lifo
 * @head: double pointer
 * @c: int
 */
void t15_stack(stack_t **head, unsigned int c)
{
	(void)head;
	(void)c;
	bus.lifi = 0;
}

/**
 * t15_queue - fifo
 * @head: double pointer
 * @c: int
 */
void t15_queue(stack_t **head, unsigned int c)
{
	(void)head;
	(void)c;
	bus.lifi = 1;
}

