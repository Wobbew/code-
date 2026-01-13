/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   targetnode.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/13 19:40:17 by wwiedijk      #+#    #+#                 */
/*   Updated: 2026/01/13 19:41:03 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

void	findtargetnode(t_list *node, t_list **targetstack)
{
	if (!targetstack)
		exit(0);
	if (node->stack == 'A')
	{
		targetnodefor_a(node, targetstack);
	}
	if (node->stack == 'B')
		targetnodefor_b(node, targetstack);
}

void	targetnodefor_a(t_list *node, t_list **targetstack)
{
	t_list	*targetnode;

	targetnode = *targetstack;
	while (targetnode)
	{
		if ((!node->target && targetnode->number < node->number)
			|| (node->target && node->target->number < targetnode->number
				&& targetnode->number < node->number))
			node->target = targetnode;
		targetnode = targetnode->next;
	}
	targetnode = *targetstack;
	if (!node->target || node->target->number > node->number)
	{
		while (targetnode)
		{
			if (((!node->target) && targetnode->number > node->number)
				|| (node->target && node->target->number < targetnode->number
					&& targetnode->number > node->number))
				node->target = targetnode;
			targetnode = targetnode->next;
		}
	}
}

void	targetnodefor_b(t_list *node, t_list **targetstack)
{
	t_list	*targetnode;

	targetnode = *targetstack;
	while (targetnode)
	{
		if ((!node->target && targetnode->number > node->number)
			|| (node->target && node->target->number > targetnode->number
				&& targetnode->number > node->number))
			node->target = targetnode;
		targetnode = targetnode->next;
	}
	targetnode = *targetstack;
	if (!node->target || node->target->number < node->number)
	{
		while (targetnode)
		{
			if (((!node->target) && targetnode->number < node->number)
				|| (node->target && node->target->number > targetnode->number
					&& targetnode->number < node->number))
				node->target = targetnode;
			targetnode = targetnode->next;
		}
	}
}

int	above_median_line(t_list *node, t_list **stack)
{
	float	median_line;

	fill_index(stack);
	median_line = count_nodes(*stack) / 2.0;
	if (median_line > node->index)
		return (1);
	if (median_line < node->index)
	{
		return (-1);
	}
	return (0);
}
