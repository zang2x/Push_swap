#include "push_swap.h"

int	biggest_index(t_node *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	sort_three(t_stack **stack)
{
	int	highest;

	highest = biggest_index((*stack)->a);
	if ((*stack)->a->index == highest)
		do_ra(stack);
	else if ((*stack)->a->next->index == highest)
		do_rra(stack);
	if ((*stack)->a->index > (*stack)->a->next->index)
		do_sa(stack);
}