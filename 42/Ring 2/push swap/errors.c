#include "Pushswap.h"
int check_args(int argc, char const *argv[])
{
	if (argc < 2)
	{
		write(2, "Error\n", 7);
		return (1);
	}
	if(argc == 2 && argv[1][0] == '\0')
	{
		write(2, "Error\n", 7);
		return (1);
	}
	return (0);
}
void same_args(t_list **stack)
{
	t_list *tmp;
	t_list *node;
	node = *stack;
	while (node)
	{
		tmp = node->next;
		
		while (tmp)
		{
			if (node->number == tmp->number)
			{
				printf("free all");
				exit(0);
			}
			tmp = tmp->next;
		}
		node = node->next;
	}
	
}