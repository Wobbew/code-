/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sortutills.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/13 17:30:19 by wwiedijk      #+#    #+#                 */
/*   Updated: 2026/01/13 19:44:24 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

bool	is_sorted(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool	is_biggest(int num, t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->number > num)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

bool	can_rotate_both(int one, int two, t_list *node)
{
	if (one == two || one == 0 || two == 0)
	{
		if (one != 0)
			node->rotate = one;
		else if (two != 0)
			node->rotate = two;
		else
			node->rotate = 0;
		node->target->rotate = node->rotate;
		return (true);
	}
	return (false);
}
