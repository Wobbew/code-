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
		if(node->target)
			printf("target number \t%d\n", node->target->number);
		printf("index \t%d\n", node->index);
		node= node->next;
	}
}