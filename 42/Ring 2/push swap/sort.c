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
