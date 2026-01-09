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
	{
		SA(stack_a);
		exit(0);
	}
	if (size == 3)
	{
		sort3(stack_a);
		exit(0);
	}
	if (size > 3)
		the_turk(stack_a, stack_b);
	// print_stack(*stack_a);
	// print_stack(*stack_b);
	exit ((free_all(stack_a, stack_b), 0));
}
void sort3(t_list **stack)
{
	t_list *last;
	t_list *first;
	first = *stack;
	last = ft_lstlast(*stack);
	if( is_sorted(*stack))
		return;
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
	// print_stack(*stack_a);
	// print_stack(*stack_b);
	while (count_nodes(*stack_a) > 3)
	{
		clear_priceinfo(stack_a, stack_b);
		fill_index(stack_b);
		fillstack(stack_a, 'A', stack_b);
		find_cheapest(stack_a);
		move_cheapest(stack_a, stack_b);
		PB(stack_a, stack_b);
		// print_stack(*stack_a);
		// print_stack(*stack_b);
		// printf("\n");
	}
	the_turk_part_two(stack_a, stack_b);
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
		i++;
	}
}
void findcost(t_list *node, t_list **targetstack, t_list **stack)
{
    findtargetnode(node, targetstack);
		fill_index(targetstack);
		if (node->index == 0 && node->target->index == 0)
		{
				node->cost = 0;
				return;
		}
    if(node->index == 0)
      node->cost = price_move1node(node->target, targetstack);
    else if (node->target->index == 0)
      node->cost = price_move1node(node, stack);
    else if(can_rotate_both(above_median_line(node->target, targetstack), 
                            above_median_line(node, stack), node))
        node->cost = price_moveboth_at_sametime(node, targetstack, stack);
    else
    {
        // Calculate separate costs and add them
        int cost1 = price_move1node(node, stack);
        int cost2 = price_move1node(node->target, targetstack);
        node->cost = cost1 + cost2;
    }
		// node->target->rotate = above_median_line(node->target, targetstack);
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
	if (tmp == 0)
		tmp = node->target->rotate;
	if(tmp >= 0)
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
	fill_index(targetstack);
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
	fill_index(stack);
	fill_index(targetstack);
	while (can_rotate_both(above_median_line(node->target, targetstack), above_median_line(node, stack), node) && (node->index != 0 && node->target->index != 0))
	{

		if(node->rotate >= 0)
			RR(stack, targetstack);
		if (node->rotate == -1)
			RRR(stack, targetstack);

		fill_index(stack);
		fill_index(targetstack);
	}
	if (node->index == 0)
		move1totop(targetstack, node->target);
	else if(node->target->index == 0)
		move1totop(stack, node);
	else
	{
		move1totop(stack, node);
		move1totop(targetstack, node->target);
	}
}
void move1totop(t_list **stack, t_list *node)
{
	fill_index(stack);
	while (node && (node->index != 0))
	{
		// printf("\nrotate%d\tnum%d\n", node->rotate, node->number);
		
		if(node->stack == 'A' && (node->index != 0))
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
		fill_index(stack);
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
	fill_index(stack);
	median_line = count_nodes(*stack) / 2.0 ;
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
		node->target->rotate = node->rotate;
		return(true);
	}
	return(false);
}
void findtargetnode(t_list *node, t_list **targetstack)
{
	if(!targetstack)
		exit(0);

	if(node->stack == 'A')
	{
		targetnodefor_a(node, targetstack);
	}
	if (node->stack == 'B')
		targetnodefor_b(node, targetstack);
	// printf("node num:%d\t targetnode num:%d\n", node->number, node->target->number);
}
void targetnodefor_a(t_list *node,t_list **targetstack)
{
	t_list	*targetnode;
	targetnode = *targetstack;
	while (targetnode)
		{
			if ((!node->target && targetnode->number < node->number) ||(node->target && node->target->number < targetnode->number && targetnode->number < node->number ))
				node->target = targetnode;
			targetnode = targetnode->next;
			
		}
	targetnode = *targetstack;
	if(!node->target || node->target->number > node->number)
	{
		while (targetnode)
		{
			if (((!node->target) && targetnode->number > node->number) || (node->target && node->target->number < targetnode->number && targetnode->number > node->number ))
				node->target = targetnode;
			targetnode = targetnode->next;
		}
	}
	// print_info(node);
}
void targetnodefor_b(t_list *node,t_list **targetstack)
{
	t_list	*targetnode;
	targetnode = *targetstack;
	while (targetnode)
		{
			if ((!node->target && targetnode->number > node->number) ||(node->target && node->target->number > targetnode->number && targetnode->number > node->number ))
				node->target = targetnode;
			targetnode = targetnode->next;
			
		}
	targetnode = *targetstack;
	if(!node->target || node->target->number < node->number)
	{
		while (targetnode)
		{
			if (((!node->target) && targetnode->number < node->number) || (node->target && node->target->number > targetnode->number && targetnode->number < node->number ))
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
		tmp->target =NULL;
		tmp = tmp->next;
	}
	tmp = *targetstack;
	while (tmp)
	{
		tmp->cheapest = false;
		tmp->cost =-1;
		tmp->rotate = 0;
		tmp->target =NULL;
		tmp = tmp->next;
	}
	
}
void	fix_stack_rotates(t_list **stack)
{
	fill_index(stack);
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
	while (!is_sorted(*stack) && above_median_line(smallest_num, stack) >= 0)
	{
		RA(stack);
	}
	while (!is_sorted(*stack) && above_median_line(smallest_num, stack) < 0)
	{
		RRA(stack);
	}
}
void the_turk_part_two(t_list **stack_a, t_list **stack_b)
{
	print_stack(*stack_a);
	print_stack(*stack_b);
	sort3(stack_a);
	while (count_nodes(*stack_b) > 0)
	{
		clear_priceinfo(stack_b, stack_a);
		fill_index(stack_a);
		fillstack(stack_b, 'B', stack_a);
		find_cheapest(stack_b);
 		move_cheapest(stack_b, stack_a);
		// print_stack(*stack_a);
		PA(stack_b, stack_a);
		// printf("\n");
		// print_stack(*stack_a);
		// printf("\n B\t");
		// print_stack(*stack_b);
		// printf("\n");
		// printf("\n");
	}
	// print_stack(*stack_a);
	fix_stack_rotates(stack_a);
	// print_stack(*stack_a);
	// print_info(*stack_a);
	// printf("\n");
	// print_stack(*stack_b);
	// print_info(*stack_b);10
	
	exit ((free_all(stack_a, stack_b), 0));
}

