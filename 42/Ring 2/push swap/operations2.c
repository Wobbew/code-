/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/13 19:53:22 by wwiedijk      #+#    #+#                 */
/*   Updated: 2026/01/13 19:53:26 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

void	rb(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	rrb(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
	write(1, "rrb\n", 4);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_b;
	last = ft_lstlast(*stack_b);
	*stack_b = first->next;
	(*stack_b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	first = *stack_a;
	last = ft_lstlast(*stack_a);
	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "rr\n", 3);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	first = *stack_a;
	last = ft_lstlast(*stack_a);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack_a = last;
	first = *stack_b;
	last = ft_lstlast(*stack_b);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack_b = last;
	write(1, "rrr\n", 4);
}
