#include "push_swap.h"

void rev_rotate(t_node **stack)
{
	t_node *last;
	t_node *new_last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	last = get_lastnb(*stack, 0);
	new_last = get_lastnb(*stack, 1);
	new_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	do_rra(t_stack **stacks)
{
	rev_rotate(&((*stacks)->a));
	printf("rra\n");
}

void	do_rrb(t_stack **stacks)
{
	rev_rotate(&((*stacks)->a));
	printf("rrb\n");
}

void	do_rrr(t_stack **stacks)
{
	rev_rotate(&((*stacks)->a));
	rev_rotate(&((*stacks)->b));
	printf("rrr\n");
}