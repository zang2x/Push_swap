#include "push_swap.h"

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

void	push_init(t_stack **stack)
{
	int	stacksize;
	int	pushes;
	int	i;

	stacksize = stack_size((*stack)->a);
	pushes = 0;
	i = 0;
	while (stacksize > 6 && i < stacksize && pushes < stacksize / 2)
	{
		if (((*stack)->a)->index <= stacksize / 2)
		{
			do_pb(stack);
			pushes++;
		}
		else
			do_ra(stack);
		i++;
	}
	while (stacksize - pushes > 3)
	{
		do_pb(stack);
		pushes++;
	}
}

void	sort_stack(t_stack **stack)
{
	int	lowest_pos;
	int	stacksize;

	stacksize = stack_size((*stack)->a);
	lowest_pos = lowest_pos_index((*stack)->a);
	if (lowest_pos > stacksize / 2)
	{
		while (lowest_pos < stacksize)
		{
			do_rra(stack);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stack);
			lowest_pos--;
		}
	}
}

void	sort(t_stack **stack)
{
	push_init(stack);
	sort_three(stack);
	while ((*stack)->b)
	{
		target_position(stack);
		get_cost(stack);
		lowcost_move(stack);
	}
	if (!is_sorted((*stack)->a))
		sort_stack(stack);
}