#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_node {
    int number;
    int index;
    int pos;
    int target;
    int cost_a;
    int cost_b;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *a;
    t_node *b;
    int size_a;
    int size_b;
} t_stack;

t_node *newnumb(int nb);
void    addnumb(t_stack **stacks, t_node *new_node);
t_node  *get_lastnb(t_node *node, int n);
int     stack_size(t_node *stack);
int    duplicated(t_node *stack);
void    getnumbers(char *args, t_stack **stacks);
void    set_index(t_node *stack);
void	sort_three(t_stack **stack);
void	do_ss(t_stack **stacks);
void	do_sa(t_stack **stacks);
void	do_sb(t_stack **stacks);
int	is_sorted(t_node *stack);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *nptr);
int	ft_strlen(const char *s);
void	do_rra(t_stack **stacks);
void	do_rrb(t_stack **stacks);
void	do_rrr(t_stack **stacks);
void	do_ra(t_stack **stacks);
void	sort(t_stack **stack);
void	sort_stack(t_stack **stack);
void	push_init(t_stack **stack);
int	biggest_index(t_node *stack);
int		lowest_pos_index(t_node *stack);
void	push(t_node **src, t_node **dst);
void	do_pa(t_stack **stacks);
void	do_pb(t_stack **stacks);
void    set_positions(t_node *stack);
int    get_target(t_stack **stack, int index, int max, int target);
void    target_position(t_stack **stacks);
void    get_cost(t_stack **stacks);
void    lowcost_move(t_stack **stacks);
void	do_rr(t_stack **stacks);
void	do_rb(t_stack **stacks);
void	rotate_b(t_stack **stacks, int *cost);
void	rotate_a(t_stack **stacks, int *cost);
void	rotate_both(t_stack **stacks, int *cost_a, int *cost_b);
void	reverse_both(t_stack **stacks, int *cost_a, int *cost_b);
int	abn(int nb);
void	do_move(t_stack **stacks, int cost_a, int cost_b);
void    swap(t_node **stack);
void	free_stack(t_node **stack);
void	free_exit(t_stack **stacks, char **tmp);
void	free_tmp(char **tmp);

#endif