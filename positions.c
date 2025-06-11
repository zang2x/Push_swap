#include "push_swap.h"

void    set_positions(t_node *stack)
{
    t_node  *tmp;
	int			i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int    get_target(t_stack **stack, int index, int max, int target)
{
	t_node	*tmp;

	tmp = (*stack)->a;
	while (tmp)
	{
		if (tmp->index > index && tmp->index < max)
		{
			max = tmp->index;
			target = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (max != INT_MAX)
		return (target);
	tmp = (*stack)->a;
	while (tmp)
	{
		if (tmp->index < max)
		{
			max = tmp->index;
			target = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (target);
}
void    target_position(t_stack **stacks)
{
    t_node	*tmp;
	int		target;

    if((*stacks)->a == NULL || (*stacks)->b == NULL)
            return;
	tmp = (*stacks)->b;
	set_positions((*stacks)->a);
	set_positions((*stacks)->b);
	target = 0;
	while (tmp)
	{
		target = get_target(stacks, tmp->index, INT_MAX, target);
		tmp->target = target;
		tmp = tmp->next;
	}
}

void    get_cost(t_stack **stacks)
{
    t_node	*tmp_a;
	t_node	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = (*stacks)->a;
	tmp_b = (*stacks)->b;
	size_a = stack_size(tmp_a);
	size_b = stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target;
		if (tmp_b->target > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
	}
}

void    lowcost_move(t_stack **stacks)
{
	t_node		*tmp;
	int			cheapest;
	int			cost_a;
	int			cost_b;

    if((*stacks)->b == NULL)
            return;
	tmp = (*stacks)->b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (abn(tmp->cost_a) + abn(tmp->cost_b) < cheapest)
		{
			cheapest = abn(tmp->cost_a) + abn(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(stacks, cost_a, cost_b);
}