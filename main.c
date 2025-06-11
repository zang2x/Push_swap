#include "push_swap.h"

void initialize_indices(t_node *stack)
{
    while (stack)
    {
        stack->index = -1;
        stack = stack->next;
    }
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	valid_input(char	*str)
{
	int	i;

	i = 0;
    if (!str || str[0] == '\0')
            return (0);
	if ((str[i] == '-' || str[i] == '+'))
		i++;
    if (str[i] == '\0')
		    return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void    push_swap(t_stack **stacks)
{
	if ((*stacks)->size_a == 2 && !is_sorted((*stacks)->a))
		do_sa(stacks);
	if ((*stacks)->size_a == 3 && !is_sorted((*stacks)->a))
		sort_three(stacks);
    if((*stacks)->size_a > 3 && !is_sorted((*stacks)->a))
        sort(stacks);
}

int    duplicated(t_node *stack)
{
    t_node *tmp;
    t_node *tmp2;

    tmp = stack;
    while(tmp)
    {
        tmp2 = tmp->next;
        while(tmp2)
        {
            if(tmp->number == tmp2->number)
                return(1);
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
    return(0);
}

void    getnumbers(char *args, t_stack **stacks)
{
    char **tmp;
    int i;
    long int nb;

    i = 0;
    tmp = ft_split(args, ' ');
    while(tmp[i] != NULL)
    {
        if(valid_input(tmp[i]))
        {
            nb = ft_atoi(tmp[i]);
            if(nb > INT_MAX || nb < INT_MIN)
                    free_exit(stacks, tmp);
            addnumb(stacks, newnumb(nb));
        }
        else
            free_exit(stacks, tmp);
        i++;
    }
    free_tmp(tmp);
}
int main(int argc, char **argv)
{
    t_stack *stacks;
    stacks = malloc(sizeof(t_stack));
    stacks->a = NULL;
    stacks->b = NULL;
    stacks->size_a = 0;
    stacks->size_b = 0;
    int i;

    i = 1;
    while (i < argc)
    {
        getnumbers(argv[i], &stacks);
        i++;
    }
    if(duplicated(stacks->a))
        free_exit(&stacks, NULL);
    stacks->size_a = stack_size((*stacks).a);
    initialize_indices(stacks->a);
    set_index((*stacks).a);
    push_swap(&stacks);
    free_stack(&stacks->a);
	free_stack(&stacks->b);
    free(stacks);
}
    