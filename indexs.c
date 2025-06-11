#include "push_swap.h"

void    set_index(t_node *stack)
{
    t_node	*ptr;
	t_node	*min_node;
	int		index;
	int		no_index;

	index = 0;
	no_index = 1;
	while (no_index)
	{
		ptr = stack;
		min_node = NULL;
		no_index = 0;
		while (ptr)
		{
			if (ptr->index == -1)
			{
				no_index= 1;
				if (!min_node || ptr->number < min_node->number)
					min_node = ptr;
			}
			ptr = ptr->next;
		}
		if (min_node)
			min_node->index = index++;
	}
}

int     stack_size(t_node *stack)
{
    int i;

    if(!stack)
        return(0);
    i = 0;
    while(stack)
    {
        stack = stack->next;
        i++;
    }
    return(i);
}

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

int		lowest_pos_index(t_node *stack)
{
	t_node	*tmp;
	int		lowest_i;
	int		lowest_pos;

	tmp = stack;
	lowest_i = INT_MAX;
	set_positions(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_i)
		{
			lowest_i = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}
