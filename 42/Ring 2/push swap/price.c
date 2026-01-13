/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   price.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/13 19:37:45 by wwiedijk      #+#    #+#                 */
/*   Updated: 2026/01/13 19:38:43 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

int	price_move1node(t_list *node, t_list **stack)
{
	int	price;
	int	tmp;

	price = 0;
	tmp = above_median_line(node, stack);
	if (tmp > 0)
		price = node->index;
	if (tmp < 0)
		price = count_nodes(*stack) - node->index;
	node->rotate = tmp;
	if (tmp == 0)
	{
		if (count_nodes(*stack) - node->index < node->index)
		{
			price = count_nodes(*stack) - node->index;
			node->rotate = -1;
		}
		else
		{
			price = node->index;
			node->rotate = 1;
		}
	}
	return (price);
}

int	price_moveboth_at_sametime(t_list *node, t_list **targetstack,
		t_list **stack)
{
	int	tmp;
	int	price;
	int	price2;

	price = 0;
	price2 = 0;
	tmp = node->rotate;
	if (tmp == 0)
		tmp = node->target->rotate;
	if (tmp >= 0)
	{
		price = node->index;
		price2 = node->target->index;
	}
	if (tmp < 0)
	{
		price = count_nodes(*stack) - node->index;
		price2 = count_nodes(*targetstack) - node->target->index;
	}
	if (price < price2)
		price = price2;
	return (price);
}

void	findcost(t_list *node, t_list **targetstack, t_list **stack)
{
	int	cost1;
	int	cost2;

	findtargetnode(node, targetstack);
	fill_index(targetstack);
	if (node->index == 0 && node->target->index == 0)
	{
		node->cost = 0;
		return ;
	}
	if (node->index == 0)
		node->cost = price_move1node(node->target, targetstack);
	else if (node->target->index == 0)
		node->cost = price_move1node(node, stack);
	else if (can_rotate_both(above_median_line(node->target, targetstack),
			above_median_line(node, stack), node))
		node->cost = price_moveboth_at_sametime(node, targetstack, stack);
	else
	{
		cost1 = price_move1node(node, stack);
		cost2 = price_move1node(node->target, targetstack);
		node->cost = cost1 + cost2;
	}
}

void	find_cheapest(t_list **stack)
{
	t_list	*node;
	t_list	*cheapest;

	node = *stack;
	cheapest = NULL;
	while (node)
	{
		if (cheapest == NULL || cheapest->cost > node->cost)
		{
			if (cheapest)
				cheapest->cheapest = false;
			cheapest = node;
			cheapest->cheapest = true;
		}
		node = node->next;
	}
}

t_list	*give_cheapest_node(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp && !tmp->cheapest)
		tmp = tmp->next;
	return (tmp);
}
