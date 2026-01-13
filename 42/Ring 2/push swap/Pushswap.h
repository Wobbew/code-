/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/13 19:54:32 by wwiedijk      #+#    #+#                 */
/*   Updated: 2026/01/13 20:01:54 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>

// tmp
# include <stdio.h>
// tmp

typedef struct s_list
{
	int				rotate;
	int				number;
	int				index;
	char			stack;
	struct s_list	*target;
	struct s_list	*prev;
	struct s_list	*next;
	int				cost;
	bool			cheapest;
}					t_list;

int					check_args(int argc, char const *argv[]);
t_list				*new_node(int number);
void				add_back(t_list **stack, t_list *new);
int					arrayintonodes(char **array, t_list **stack);
int					make_stack(t_list **stack, int argc, char const *argv[]);
bool				is_sorted(t_list *stack);
int					count_nodes(t_list *stack);
int					sort(t_list **stack_a, t_list **stack_b);
void				sa(t_list **stack_a);
void				print_stack(t_list *stack);
void				print_info(t_list *node);
bool				is_biggest(int num, t_list *stack);
void				sort3(t_list **stack);
t_list				*ft_lstlast(t_list *lst);
void				findtargetnode(t_list *node, t_list **targetstack);
void				findcost(t_list *node, t_list **targetstack,
						t_list **stack);
int					price_move1node(t_list *node, t_list **stack);
void				fillstack(t_list **stack, char watstack,
						t_list **targetstack);
void				fill_index(t_list **stack);
void				fillnode(t_list *node, t_list **stack, char watstack,
						t_list **targetstack);
void				the_turk_part_two(t_list **stack_a, t_list **stack_b);
void				the_turk(t_list **stack_a, t_list **stack_b);
int					above_median_line(t_list *node, t_list **stack);
void				ra(t_list **stack_a);
void				rb(t_list **stack);
void				rr(t_list **stack_a, t_list **stack_b);
void				rra(t_list **stack_a);
void				rrb(t_list **stack);
void				rrr(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
void				pa(t_list **stack, t_list **stack_a);
void				same_args(t_list **stack);
int					check_if_number(char *str);
bool				can_rotate_both(int one, int two, t_list *node);
int					price_moveboth_at_sametime(t_list *node,
						t_list **targetstack, t_list **stack);
void				move2totop(t_list **targetstack, t_list **stack,
						t_list *node);
void				find_cheapest(t_list **stack);
void				move1totop(t_list **stack, t_list *node);
void				clear_priceinfo(t_list **stack, t_list **targetstack);
void				fix_stack_rotates(t_list **stack);
void				move_cheapest(t_list **stack, t_list **targetstack);
void				targetnodefor_a(t_list *node, t_list **targetstack);
void				targetnodefor_b(t_list *node, t_list **targetstack);
void				free_all(t_list **stack_a, t_list **stack_b);
#endif