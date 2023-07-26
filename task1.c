#include "monty.h"
/**
 * t1_pint -  prints the value at the top of the stack
 * @head: double pointer
 * @c: int unused
 */
void t1_pint(stack_t **head, unsigned int c)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", c);
		fclose(bus.file);
		free(bus.content);
		m_freestack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
