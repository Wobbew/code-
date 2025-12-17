#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdbool.h>
# include <stdlib.h>
# include "libft/libft.h"

//tmp
#include <stdio.h>
//tmp

typedef struct s_list
{
	int			number;
	int 		index;
	char		stack;
	struct s_list	*target;
	struct s_list	*prev;
	struct s_list	*next;
	int			cost;
	bool		cheapest;
}					t_list;

int check_args(int argc, char const *argv[]);
t_list	*new_node(int number);
void	add_back(t_list **stack, t_list *new);
int arrayintonodes(char ** array, t_list **stack);
int make_stack(t_list **stack, int argc, char const *argv[]);
bool is_sorted(t_list *stack);
int count_nodes(t_list *stack);
int sort(t_list **stack_a, t_list **stack_b);
void	SA(t_list **stack_a);
void	print_stack(t_list *stack);
bool is_biggest(int num, t_list *stack);
void sort3(t_list **stack);
t_list	*ft_lstlast(t_list *lst);
void findtargetnode(t_list *node, t_list **targetstack);
void findcheapest(t_list *node, t_list **targetstack);//, t_list **stack
void	fillnode(t_list **stack, char watstack, t_list **targetstack);
void the_turk(t_list **stack_a);//, t_list **stack_b
void RA(t_list **stack_a);
void RRA(t_list **stack_a);
#endif