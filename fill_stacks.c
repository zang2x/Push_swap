#include "push_swap.h"

t_node *newnumb(int nb)
{
    t_node *new;
    new = malloc(sizeof(t_node));
    if(!new)
        return(NULL);
    new->number = nb;
    new->index = -1;
    new->next = NULL;
    return(new);
}

void    addnumb(t_stack **stacks, t_node *new_node)
{
    t_node *last;

    if(!new_node)
        return;
    if(!(*stacks)->a)
    {
        (*stacks)->a = new_node;
        return;
    }
    last = get_lastnb((*stacks)->a, 0);
    last->next = new_node;
}

t_node *get_lastnb(t_node *node, int n)
{
    if (!node)
        return (NULL);
    if (n == 0)
    {
        while (node->next != NULL)
            node = node->next;
        return node;
    }
    if (n == 1)
    {
        if (!node->next)
            return (NULL);

        while (node->next->next != NULL)
            node = node->next;
        return node;
    }
    return (NULL);
}
