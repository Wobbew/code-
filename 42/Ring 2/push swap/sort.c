#include "Pushswap.h"
int sort(t_list **stack_a, t_list **stack_b)
{
	int size;
	size = 0;
	// t_list *tmp;
	print_stack(*stack_a);
	if (is_sorted(*stack_a))
		exit(0); // need to free
	is_sorted(*stack_b);
	size = count_nodes(*stack_a);
	if (size == 2)
		SA(stack_a);
	if (size == 3)
		sort3(stack_a);
	if (size > 3)
		the_turk(stack_a);
	print_stack(*stack_a);
	return (0);
}
void sort3(t_list **stack)
{
	t_list *last;
	t_list *first;
	first = *stack;
	last = ft_lstlast(*stack);
	if (is_biggest(last->number, *stack))
		SA(stack);
	else if (is_biggest(first->number, *stack))
	{
		RA(stack);
		if (!is_sorted(*stack))
			SA(stack);
	}
	else
	{
		RRA(stack);
		if (!is_sorted(*stack))
			SA(stack);
	}
}
void the_turk(t_list **stack_a)//, t_list **stack_b
{
	fillnode(stack_a, 'A', NULL);
	
}

void	fillnode(t_list **stack, char watstack, t_list **targetstack)
{
	int i;
	t_list *node;
	node = *stack;
	i = 0;
	if (watstack == 'A' && targetstack)
		fillnode(targetstack, 'B', NULL);
	else if (watstack == 'B' && targetstack)
		fillnode(targetstack, 'A', NULL);
	while (node)
	{
		node->index = i;
		node->stack = watstack;
		if (targetstack)
			findcheapest(node,targetstack);//, stack
		else
		{
			node->target = NULL;
			node->cheapest =false;
			node->cost = -1;
		}
	}
	
}

void findcheapest(t_list *node, t_list **targetstack)//, t_list **stack
{
	findtargetnode(node, targetstack);

}
void findtargetnode(t_list *node, t_list **targetstack)
{
	t_list *targetnode;
	targetnode = *targetstack;
	if ((!node->target) && (targetnode))
		node->target = targetnode;
	if(node->stack == 'A')
	{
		while (targetnode)
		{
			if (node->target->number > targetnode->number && targetnode->number <= node->number)
				node->target = targetnode;
			targetnode = targetnode->next;
		}
	}
	printf("node num:%d\t targetnode num:%d\n", node->number, node->target->number);
}

