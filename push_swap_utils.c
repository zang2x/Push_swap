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