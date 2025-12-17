#include "Pushswap.h"
void	SA(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;
	
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;

	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack_a = second;
	write(1, "SA\n", 3);
}

void RA(t_list **stack_a)
{
	t_list *first;
	t_list *last;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return;
	first = *stack_a;
	last = ft_lstlast(*stack_a);
	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "RA\n", 3);
}
void RRA(t_list **stack_a)
{
	t_list *first;
	t_list *last;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return;
	first = *stack_a;
	last = ft_lstlast(*stack_a);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack_a = last;
	write(1, "RRA\n", 4);
}

void PB(t_list )