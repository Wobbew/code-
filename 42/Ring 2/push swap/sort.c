#include "Pushswap.h"
int sort(t_list **stack_a, t_list **stack_b)
{
	int size;
	size = 0;
	// t_list *tmp;
	// print_stack(*stack_a);
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
	// print_stack(*stack_a);
	// print_stack(*stack_b);
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
	// fillstack(stack_a, 'A', stack_b);
	if(count_nodes(*stack_a) == 3)
		the_turk_part_two(stack_a, stack_b);
	while (count_nodes(*stack_a) > 3)
	{
		clear_priceinfo(stack_a, stack_b);
		fill_index(stack_b);
		fillstack(stack_a, 'B', stack_b);
		find_cheapest(stack_a);
		move_cheapest(stack_a, stack_b);
		PA(stack_a, stack_b);
		// print_stack(*stack_a);
		// print_stack(*stack_b);
	}
	// the_turk_part_two(stack_a, stack_b);
}

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
		// print_stack(*stack);
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
	}
}
void findcost(t_list *node, t_list **targetstack, t_list **stack)
{
    findtargetnode(node, targetstack);
		fill_index(targetstack);
    if(node->index == 0)
    {
        node->cost = price_move1node(node->target, targetstack);
    }
    else if (node->target->index == 0)
    {
        node->cost = price_move1node(node, stack);
    }
    else if(can_rotate_both(above_median_line(node->target, targetstack), 
                            above_median_line(node, stack), node))
    {
        node->cost = price_moveboth_at_sametime(node, targetstack, stack);
    }
    else
    {
        // Calculate separate costs and add them
        int cost1 = price_move1node(node, stack);
        int cost2 = price_move1node(node->target, targetstack);
        node->cost = cost1 + cost2;
    }
		// printf("\nNode number:%d\tcost:%d\t rotate:%d\n", node->number, node->cost, node->rotate);
}

int price_move1node(t_list *node, t_list **stack)
{
	int price;
	int tmp;
	price =0;
	tmp = above_median_line(node, stack);
	if (tmp > 0)
		price = node->index;
	if (tmp < 0)
		price = count_nodes(*stack) - node->index;
	node->rotate = tmp;
	// print_info(node);
	if(tmp == 0)
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
	return(price);
}


int price_moveboth_at_sametime (t_list *node, t_list **targetstack, t_list **stack)
{
	int tmp;
	int price;
	int price2;
	price = 0;
	price2 = 0;
	tmp = node->rotate;
	if(tmp >0)
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
	{
		price = price2;
	}
	return(price);
}
void find_cheapest(t_list **stack)
{
	t_list *node;
	t_list *cheapest;
	node = *stack;
	cheapest = NULL;
	while (node)
	{
		if(cheapest == NULL || cheapest->cost > node->cost)
		{
			if (cheapest)
				cheapest->cheapest = false;
			cheapest = node;
			cheapest->cheapest = true;
		}
		node = node->next;
	}
	
}
void move_cheapest(t_list **stack, t_list **targetstack)
{
	
	t_list *tmp;
	t_list *cheapest;
	tmp = *stack;
	while (tmp && !tmp->cheapest)
		tmp =tmp->next;
	cheapest = tmp;
	// print_info(cheapest);
	// print_stack(*targetstack);
	if (cheapest->index == 0 && cheapest->target->index == 0)
		return;
	if (cheapest->index == 0)
		move1totop(targetstack, cheapest->target);
	else if(cheapest->target->index == 0)
		move1totop(stack, cheapest);
	else
		move2totop(targetstack, stack, cheapest);
}
void move2totop(t_list **targetstack,t_list **stack, t_list *node)
{
	
	while (can_rotate_both(above_median_line(node->target, targetstack), above_median_line(node, stack), node) && (node->index != 0 || node->target->index != 0))
	{
		fill_index(stack);
		fill_index(targetstack);
		if(node->rotate == 1)
			RRR(stack, targetstack);
		if (node->rotate == -1)
			RR(stack, targetstack);
	}
	if (node->index == 0)
		move1totop(targetstack, node->target);
	else if(node->target->index == 0)
		move1totop(stack, node);
}
void move1totop(t_list **stack, t_list *node)
{
	while (node && (node->index != 0))
	{
		// printf("\nrotate%d\tnum%d\n", node->rotate, node->number);
		fill_index(stack);
		if(node->stack == 'A')
		{
			if(node->rotate == 1)
				RA(stack);
			else
				RRA(stack);
		}
		if(node->stack == 'B')
		{
			if(node->rotate == 1)
				RB(stack);
			else
				RRB(stack);
		}
	}

}

t_list *give_cheapest_node(t_list **stack)
{
	t_list *tmp;
	tmp = *stack;
	while (tmp && !tmp->cheapest)
		tmp =tmp->next;
	return tmp;
}
int above_median_line(t_list *node, t_list **stack)
{
	float median_line;
	median_line = count_nodes(*stack) / 2. ;
	// print_info(node);
	// print_stack(*stack);
	if (median_line > node->index)
		return(1);
	if (median_line < node->index)
	{
		return(-1);
	}
		return(0);
}
bool can_rotate_both(int one, int two, t_list *node)
{
	if (one == two || one == 0 || two == 0)
	{
		// printf("one:%d\ttwo:%d\n", one, two);
		if(one != 0)
			node->rotate = one;
		else if (two != 0)
			node->rotate = two;
		else 
			node->rotate = 0;
		return(true);
	}
	return(false);
}
void findtargetnode(t_list *node, t_list **targetstack)
{
	t_list *targetnode;
	if(!targetstack)
		exit(0);
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
		targetnodefor_b(node, targetstack);
	// printf("node num:%d\t targetnode num:%d\n", node->number, node->target->number);
}
void targetnodefor_b(t_list *node,t_list **targetstack)
{
	t_list	*targetnode;
	targetnode = *targetstack;
	while (targetnode)
		{
			if ((node->target->number > targetnode->number && targetnode->number < node->number )|| node->target->number <= node->number)
				node->target = targetnode;
			targetnode = targetnode->next;
			
		}
	targetnode = *targetstack;
	if(node->target->number < node->number)
	{
		while (targetnode)
		{
			if ((node->target->number < targetnode->number && targetnode->number < node->number )|| node->target->number <= node->number)
				node->target = targetnode;
			targetnode = targetnode->next;
		}
	}
	// print_info(node);
}
void clear_priceinfo(t_list **stack, t_list **targetstack)
{
	t_list *tmp;
	tmp = *stack;
	while (tmp)
	{
		tmp->cheapest = false;
		tmp->cost =-1;
		tmp->rotate = 0;
		tmp = tmp->next;
	}
	tmp = *targetstack;
	while (tmp)
	{
		tmp->cheapest = false;
		tmp->cost =-1;
		tmp->rotate = 0;
		tmp = tmp->next;
	}
	
}
void	fix_stack_rotates(t_list **stack)
{
	t_list *tmp;
	t_list	*smallest_num;
	tmp = *stack;
	smallest_num = *stack;
	while (tmp)
	{
		if (smallest_num->number > tmp->number)
			smallest_num = tmp;
		tmp = tmp->next;
	}
	while (smallest_num->next && smallest_num->index != 0 && above_median_line(smallest_num, stack) <= 0)
	{
		smallest_num->index = smallest_num->index +1;
		RA(stack);
	}
	while (smallest_num->index != 0 && above_median_line(smallest_num, stack) > 0)
	{

		smallest_num->index = smallest_num->index -1;
		RRA(stack);
	}
}
void the_turk_part_two(t_list **stack_a, t_list **stack_b)
{
	sort3(stack_a);
	while (count_nodes(*stack_b) > 0)
	{
		clear_priceinfo(stack_b, stack_a);
		fill_index(stack_a);
		fillstack(stack_b, 'B', stack_a);
		find_cheapest(stack_b);
		move_cheapest(stack_b, stack_a);
		PA(stack_b, stack_a);
		print_stack(*stack_a);
		print_stack(*stack_b);
	}
	fix_stack_rotates(stack_a);
	print_stack(*stack_a);
	// print_info(*stack_a);
	// printf("\n");
	// print_stack(*stack_b);
	// print_info(*stack_b);
	
	exit(0);
}

// void	move_cheapest(t_list stack,t_list moveto)
// {
	
// }
