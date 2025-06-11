#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
			return;
	tmp = *stack;
	*stack = (*stack)->next;
	last = get_lastnb(*stack, 0);
	tmp->next = NULL;
	last->next = tmp;
}

void	do_ra(t_stack **stacks)
{
	rotate(&(*stacks)->a);
	write(1, "ra\n", 3);
}

void	do_rb(t_stack **stacks)
{
	rotate(&(*stacks)->b);
	write(1, "rb\n", 3);
}

void	do_rr(t_stack **stacks)
{
	rotate(&(*stacks)->a);
	rotate(&(*stacks)->b);
	write(1, "rr\n", 3);
}