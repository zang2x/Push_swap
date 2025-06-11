#include "push_swap.h"

int	abn(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}


void	free_stack(t_node **stack)

{
	t_node	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	free_tmp(char **tmp)
{
	int i;
	
	i = 0;
	if (!tmp)
		return;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	free_exit(t_stack **stacks, char **tmp)
{
    if (stacks && *stacks)
    {
        if ((*stacks)->a)
            free_stack(&(*stacks)->a);
        if ((*stacks)->b)
            free_stack(&(*stacks)->b);
		free(*stacks);
		*stacks = NULL;
    }
	if(tmp && *tmp)
		free_tmp(tmp);
	write(2, "Error\n", 6);
	exit(1);
}