/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/13 17:30:25 by wwiedijk      #+#    #+#                 */
/*   Updated: 2026/01/13 20:02:23 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

int	sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = 0;
	if (is_sorted(*stack_a))
		exit((free_all(stack_a, stack_b), 0));
	size = count_nodes(*stack_a);
	if (size == 2)
	{
		sa(stack_a);
		exit((free_all(stack_a, stack_b), 0));
	}
	if (size == 3)
	{
		sort3(stack_a);
		exit(0);
	}
	if (size > 3)
		the_turk(stack_a, stack_b);
	exit((free_all(stack_a, stack_b), 0));
}

void	sort3(t_list **stack)
{
	t_list	*last;
	t_list	*first;

	first = *stack;
	last = ft_lstlast(*stack);
	if (is_sorted(*stack))
		return ;
	if (is_biggest(last->number, *stack))
		sa(stack);
	else if (is_biggest(first->number, *stack))
	{
		ra(stack);
		if (!is_sorted(*stack))
			sa(stack);
	}
	else
	{
		rra(stack);
		if (!is_sorted(*stack))
			sa(stack);
	}
}

void	the_turk(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	if (count_nodes(*stack_a) == 3)
		the_turk_part_two(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (count_nodes(*stack_a) == 3)
		the_turk_part_two(stack_a, stack_b);
	while (count_nodes(*stack_a) > 3)
	{
		clear_priceinfo(stack_a, stack_b);
		fill_index(stack_b);
		fillstack(stack_a, 'A', stack_b);
		find_cheapest(stack_a);
		move_cheapest(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	the_turk_part_two(stack_a, stack_b);
}

void	fix_stack_rotates(t_list **stack)
{
	t_list	*tmp;
	t_list	*smallest_num;

	fill_index(stack);
	tmp = *stack;
	smallest_num = *stack;
	while (tmp)
	{
		if (smallest_num->number > tmp->number)
			smallest_num = tmp;
		tmp = tmp->next;
	}
	while (!is_sorted(*stack) && above_median_line(smallest_num, stack) >= 0)
	{
		ra(stack);
	}
	while (!is_sorted(*stack) && above_median_line(smallest_num, stack) < 0)
	{
		rra(stack);
	}
}

void	the_turk_part_two(t_list **stack_a, t_list **stack_b)
{
	sort3(stack_a);
	while (count_nodes(*stack_b) > 0)
	{
		clear_priceinfo(stack_b, stack_a);
		fill_index(stack_a);
		fillstack(stack_b, 'B', stack_a);
		find_cheapest(stack_b);
		move_cheapest(stack_b, stack_a);
		pa(stack_b, stack_a);
	}
	fix_stack_rotates(stack_a);
	exit((free_all(stack_a, stack_b), 0));
}
