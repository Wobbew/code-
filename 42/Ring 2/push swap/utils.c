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
		printf("\n");
		if(node->target)
		{
			
			printf("cost\t%d\n", node->cost);
			printf("target number \t%d\n", node->target->number);
		}
		printf("num\t%d\n", node->number);
		printf("rotate\t%d\n", node->rotate);
		printf("index \t%d\n", node->index);
		node= node->next;
		
	}
}
void	vo