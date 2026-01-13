/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_node.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/13 19:46:30 by wwiedijk      #+#    #+#                 */
/*   Updated: 2026/01/13 20:06:38 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

void	move_cheapest(t_list **stack, t_list **targetstack)
{
	t_list	*tmp;
	t_list	*cheapest;

	fill_index(targetstack);
	tmp = *stack;
	while (tmp && !tmp->cheapest)
		tmp = tmp->next;
	cheapest = tmp;
	if (cheapest->index == 0 && cheapest->target->index == 0)
		return ;
	if (cheapest->index == 0)
		move1totop(targetstack, cheapest->target);
	else if (cheapest->target->index == 0)
		move1totop(stack, cheapest);
	else
		move2totop(targetstack, stack, cheapest);
}

void	move2totop(t_list **targetstack, t_list **stack, t_list *node)
{
	fill_index(stack);
	fill_index(targetstack);
	while (can_rotate_both(above_median_line(node->target, targetstack),
			above_median_line(node, stack), node) && (node->index != 0
			&& node->target->index != 0))
	{
		if (node->rotate >= 0)
			rr(stack, targetstack);
		if (node->rotate == -1)
			rrr(stack, targetstack);
		fill_index(stack);
		fill_index(targetstack);
	}
	if (node->index == 0)
		move1totop(targetstack, node->target);
	else if (node->target->index == 0)
		move1totop(stack, node);
	else
	{
		move1totop(stack, node);
		move1totop(targetstack, node->target);
	}
}

void	move1totop(t_list **stack, t_list *node)
{
	fill_index(stack);
	while (node && (node->index != 0))
	{
		if (node->stack == 'A' && (node->index != 0))
		{
			if (node->rotate == 1)
				ra(stack);
			else
				rra(stack);
		}
		if (node->stack == 'B')
		{
			if (node->rotate == 1)
				rb(stack);
			else
				rrb(stack);
		}
		fill_index(stack);
	}
}
