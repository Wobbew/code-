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
		the_turk(stack_a, stack_b);
	print_stack(*stack_a);
	print_stack(*stack_b);
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
void the_turk(t_list **stack_a, t_list **stack_b)
{

	PB(stack_a, stack_b);
	if(count_nodes(*stack_a) == 3)
		the_turk_part_two(stack_a, stack_b);
	PB(stack_a, stack_b);
	fillnode(stack_a, 'A', stack_b);
	if(count_nodes(*stack_a) == 3)
		the_turk_part_two(stack_a, stack_b);
	// print_info(*stack_a);
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
			findcost(node,targetstack);//, stack
		else
		{
			node->target = NULL;
			node->cheapest =false;
			node->cost = -1;
		}
		i++;
		node =node->next;
	}
	
}

void findcost(t_list *node, t_list **targetstack)//, t_list **stack
{
	int cost;
	cost = 0;
	findtargetnode(node, targetstack);
	if(node->index == 0 || node->target->index == 0)
	{

	}

}

int price_move1node(t_list *node, t_list **stack)
{
	int price;
	int tmp;
	price =0;
	tmp = above_median_line(node, stack);
	return(price);
}
int above_median_line(t_list *node, t_list **stack)
{
	float median_line;
	median_line =count_nodes(*stack) / 2;
	printf("%f\n%d",median_line, node->index);
	return(0);
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
			if ((node->target->number < targetnode->number && targetnode->number <= node->number )|| node->target->number >= node->number)
				node->target = targetnode;
			targetnode = targetnode->next;
		}
	}
	if (node->stack == 'B')
	{
		while (targetnode)
		{
			if ((node->target->number > targetnode->number && targetnode->number >= node->number )|| node->target->number <= node->number)
				node->target = targetnode;
			targetnode = targetnode->next;
		}
	}
	printf("node num:%d\t targetnode num:%d\n", node->number, node->target->number);
}
void the_turk_part_two(t_list **stack_a, t_list **stack_b)
{
	fillnode(stack_a, 'A', stack_b);
	sort3(stack_a);
	fillnode(stack_b, 'B', stack_a);
	while (stack_a)
	{
		
	}
	print_stack(*stack_a);
}

// void	move_cheapest(t_list stack,t_list moveto)
// {
	
// }
