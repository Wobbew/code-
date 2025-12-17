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