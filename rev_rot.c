#include "push_swap.h"

void rev_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*new_last;

	if (!stack || !*stack || !(*stack)->next)
			return;
	new_last = *stack;
	while (new_last->next && new_last->next->next)
		new_last = new_last->next;

	last = new_last->next;
	new_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	do_rra(t_stack **stacks)
{
	rev_rotate(&((*stacks)->a));
	write(1, "rra\n", 5);
}

void	do_rrb(t_stack **stacks)
{
	rev_rotate(&((*stacks)->b));
	write(1, "rrb\n", 5);
}

void	do_rrr(t_stack **stacks)
{
	rev_rotate(&((*stacks)->a));
	rev_rotate(&((*stacks)->b));
	write(1, "rrr\n", 5);
}