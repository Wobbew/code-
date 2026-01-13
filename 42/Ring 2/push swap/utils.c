/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/13 17:30:06 by wwiedijk      #+#    #+#                 */
/*   Updated: 2026/01/13 19:02:41 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d\t", stack->number);
		stack = stack->next;
	}
	printf("\n");
}

void	print_info(t_list *node)
{
	while (node)
	{
		printf("\n");
		if (node->target)
		{
			printf("cost\t%d\n", node->cost);
			printf("target number \t%d\n", node->target->number);
		}
		printf("num\t%d\n", node->number);
		printf("rotate\t%d\n", node->rotate);
		printf("index \t%d\n", node->index);
		node = node->next;
	}
}

void	free_all(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*node;

	node = *stack_a;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*stack_a = NULL;
	if (!stack_b)
	{
		return ;
	}
	node = *stack_b;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*stack_b = NULL;
}

int	count_nodes(t_list *stack)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = stack;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
