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

void	do_rb(t_stack **stacks)
{
	rotate(&(*stacks)->b);
	printf("rb\n");
}

void	do_rr(t_stack **stacks)
{
	rotate(&(*stacks)->a);
	rotate(&(*stacks)->b);
	printf("rr\n");
}