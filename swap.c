#include "push_swap.h"

void    swap(t_node **stack)
{
	t_node	*tmp;

	if (!*stack || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	do_sa(t_stack **stacks)
{
	swap(&((*stacks)->a));
	write(1, "sa\n", 3);
}

void	do_sb(t_stack **stacks)
{
	swap(&((*stacks)->b));
	write(1, "sb\n", 3);
}

void	do_ss(t_stack **stacks)
{
	swap(&((*stacks)->a));
    swap(&((*stacks)->b));
	write(1, "ss\n", 3);
}

