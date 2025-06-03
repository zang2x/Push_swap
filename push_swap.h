#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_node {
    int number;
    int index;
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
int    duplicated(t_stack **stacks);
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