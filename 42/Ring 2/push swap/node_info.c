#include "Pushswap.h"

void	fillstack(t_list **stack, char watstack, t_list **targetstack)
{
	t_list *node;
	node = *stack;
	if (watstack == 'A' && targetstack)
		fillstack(targetstack, 'B', NULL);
	else if (watstack == 'B' && targetstack)
		fillstack(targetstack, 'A', NULL);
	while (node)
	{
		fillnode(node, stack,  watstack, targetstack);
		node =node->next;
	}
	
}
void fillnode(t_list *node, t_list **stack, char watstack, t_list **targetstack)
{
	if (node->prev)
		node->index = node->prev->index + 1;
	else
		node->index = 0;
	node->stack = watstack;
	if (targetstack)
		findcost(node,targetstack, stack);
	else
	{
		node->target = NULL;
		node->cheapest =false;
		node->cost = -1;
	}
	
}
void fill_index(t_list **stack)
{
	int i;
	t_list *node;
	node = *stack;
	i = 0;
	while (node)
	{
		node->index = i;
		node = node->next;
		i++;
	}
}