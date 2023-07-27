#include "monty.h"

/**
 * _div -  divides the second top element of the stack
 * by the top element
 * @head: double pointer
 * @c: int
 */
void t7_div(stack_t **head, unsigned int c)
{
	stack_t *head0;
	int a;

	m_function(*head, c, "can't div, stack too short",1);
	head0 = *head;
	if (head0->n == 0)
	{
		m_function(*head, c, "division by zero",0);
	}
	a = head0->next->n / head0->n;
	head0->next->n = a;
	*head = head0->next;
	free(head0);
}

/**
 * t8_mul - multiplies the second top element of the stack wit
 * h the top element
 * @head: double pointer
 * @c: int
 */
void t8_mul(stack_t **head, unsigned int c)
{
	stack_t *head0;
	int a;

	m_function(*head, c, "can't mul, stack too short", 1);
	head0 = *head;
	a = head0->next->n * head0->n;
	head0->next->n = a;
	*head = head0->next;
	free(head0);
}

/**
 * t9_mod - computes the rest of the division of the second/top
 * @head: double pointer
 * @c: int
 */
void t9_mod(stack_t **head, unsigned int c)
{
	stack_t *head0;
	int a;

	m_function(*head, c, "can't mod, stack too short", 1);
	head0 = *head;
	if (head0->n == 0)
	{
		m_function(*head, c, "division by zero", 0);
	}
	a = head0->next->n % head0->n;
	head0->next->n = a;
	*head = head0->next;
	free(head0);
}

