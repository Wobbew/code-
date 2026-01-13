/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/13 17:30:32 by wwiedijk      #+#    #+#                 */
/*   Updated: 2026/01/13 19:53:36 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

void	sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	if (first->next)
		first->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack_a = second;
	write(1, "sa\n", 3);
}

void	ra(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = ft_lstlast(*stack_a);
	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = ft_lstlast(*stack_a);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	t_list	*first_b;

	if (!stack_a || !(*stack_a))
		return ;
	first_a = *stack_a;
	first_b = *stack_b;
	*stack_a = first_a->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	first_a->next = first_b;
	first_a->prev = NULL;
	if (first_b)
		first_b->prev = first_a;
	*stack_b = first_a;
	write(1, "pb\n", 3);
}

void	pa(t_list **stack, t_list **stack_a)
{
	t_list	*first;
	t_list	*first_a;

	first = *stack;
	first_a = *stack_a;
	if (first->next)
		first->next->prev = first->prev;
	*stack = first->next;
	first->next = first_a;
	first->prev = NULL;
	if (first_a)
		first_a->prev = first;
	*stack_a = first;
	write(1, "pa\n", 3);
}
