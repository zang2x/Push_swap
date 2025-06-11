#include "push_swap.h"

void push(t_node **src, t_node **dst)
{
    t_node *tmp;

    if (*src == NULL)
        return;
    tmp = (*src)->next;
    (*src)->next = *dst;
    *dst = *src;
    *src = tmp;
}

void	do_pa(t_stack **stacks)
{
	push(&(*stacks)->b, &(*stacks)->a);
	write(1, "pa\n", 3);
}

void	do_pb(t_stack **stacks)
{
	push(&(*stacks)->a, &(*stacks)->b);
	write(1, "pb\n", 3);
}