#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*last;

	tmp = *stack;
	*stack = (*stack)->next;
	last = get_lastnb(*stack, 0);
	tmp->next = NULL;
	last->next = tmp;
}

void	do_ra(t_stack **stacks)
{
	rotate(&(*stacks)->a);
	printf("ra\n");
}