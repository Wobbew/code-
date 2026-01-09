#include "Pushswap.h"
void SA(t_list **stack_a)
{
    t_list *first;
    t_list *second;
    
    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return;
    
    first = *stack_a;
    second = first->next;
    
    first->next = second->next;
    if (first->next)  
        first->next->prev = first; 

    second->prev = NULL;
    second->next = first;
    first->prev = second;
    
    *stack_a = second;
    write(1, "sa\n", 3);
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
	write(1, "ra\n", 3);
}
void RRA(t_list **stack_a)
{
    t_list *first;
    t_list *last;
    
    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return;
    
    first = *stack_a;
    last = ft_lstlast(*stack_a);
    
    // Disconnect last from the list
    last->prev->next = NULL;  // This is fine
    
    // Move last to front
    last->prev = NULL;
    last->next = first;
    first->prev = last;
    *stack_a = last;
    
    write(1, "rra\n", 4);
}

void PB(t_list **stack_a, t_list **stack_b)
{
    t_list *first_a;
    t_list *first_b;
    
    if (!stack_a || !(*stack_a))
        return;
    
    first_a = *stack_a;
    first_b = *stack_b;
    
    // Remove first_a from stack_a
    *stack_a = first_a->next;
    if (*stack_a)
        (*stack_a)->prev = NULL; 
    
    // Add first_a to stack_b
    first_a->next = first_b;
    first_a->prev = NULL;
    if (first_b)
        first_b->prev = first_a;
    
    *stack_b = first_a;
    write(1, "pb\n", 3);
}
void PA(t_list **stack, t_list **stack_a)
{
	t_list *first;
	t_list *first_a;

	first = *stack;
	first_a = *stack_a;
	if(first->next)
		first->next->prev = first->prev;
	*stack = first->next;
	first->next = first_a;
	first->prev = NULL;
	if(first_a)
		first_a->prev= first;
	*stack_a = first;
	write(1,"pa\n", 3);
}
void RB(t_list **stack)
{
	t_list *first;
	t_list *last;

	if (!stack || !(*stack) || !(*stack)->next)
		return;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "rb\n", 3);
}
void RRB(t_list **stack)
{
	t_list *first;
	t_list *last;

	if (!stack || !(*stack) || !(*stack)->next)
		return;
	first = *stack;
	last = ft_lstlast(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
	write(1, "rrb\n", 4);
}
void RR(t_list **stack_a, t_list **stack_b)
{
	t_list *first;
	t_list *last;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return;
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return;
	first = *stack_b;
	last = ft_lstlast(*stack_b);
	*stack_b = first->next;
	(*stack_b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	first = *stack_a;
	last = ft_lstlast(*stack_a);
	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;

	write(1, "rr\n", 3);
}
void RRR(t_list **stack_a, t_list **stack_b)
{
	t_list *first;
	t_list *last;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return;
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return;
	first = *stack_a;
	last = ft_lstlast(*stack_a);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack_a = last;

	first = *stack_b;
	last = ft_lstlast(*stack_b);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack_b = last;
	write(1, "rrr\n", 4);
}
