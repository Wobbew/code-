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
void	free_all(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	t_list *node;
	
	node = *stack_a;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*stack_a = NULL;
	
	if (!stack_b)
	{
		return;
	}
	node = *stack_b;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*stack_b = NULL;
}