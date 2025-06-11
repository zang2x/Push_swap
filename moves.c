#include "push_swap.h"

void	reverse_both(t_stack **stacks, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(stacks);
	}
}

void	rotate_both(t_stack **stacks, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(stacks);
	}
}

void	rotate_a(t_stack **stacks, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(stacks);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(stacks);
			(*cost)++;
		}
	}
}

void	rotate_b(t_stack **stacks, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(stacks);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(stacks);
			(*cost)++;
		}
	}
}

void	do_move(t_stack **stacks, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		reverse_both(stacks, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(stacks, &cost_a, &cost_b);
	rotate_a(stacks, &cost_a);
	rotate_b(stacks, &cost_b);
	do_pa(stacks);
}