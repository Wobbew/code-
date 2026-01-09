#include "Pushswap.h"
t_list	*new_node(int number)
{
	t_list	*node;
	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->rotate = 0;
	node->number = number;
	node->next = NULL;
	node->prev = NULL;
	node->target = NULL;
	node->index = -1;
	node->stack = '\0';
	node->cost = -1;
	return (node);
}
void	add_back(t_list **stack, t_list *new)
{
	t_list	*last;

	if (!stack || (!stack && !new))
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}
int arrayintonodes(char ** array, t_list **stack)
{
	int i;
	int num;
	t_list *nodetmp;
	i = 0;
	while (array[i])
	{
		num =ft_atoi(array[i]);
		nodetmp = new_node(num);
		if (!nodetmp)
			return (1);
		add_back(stack, nodetmp);
		i++;
	}
	return (0);
}
int make_stack(t_list **stack, int argc, char const *argv[])
{
	int i;
	i = 1;
 	while (i < argc)
	{
		if(arrayintonodes(ft_split(argv[i], ' '), stack))
			return (1);
		i++;
	}
	same_args(stack);
	return (0);
}
int count_nodes(t_list *stack)
{
	int count;
	t_list *tmp;
	count = 0;
	tmp = stack;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
