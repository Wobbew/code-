#include "Pushswap.h"
bool is_sorted(t_list *stack)
{
	t_list *tmp;
	tmp =stack;
	while (tmp && tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return false;
		tmp = tmp->next;
	}
	return true;
}
bool is_biggest(int num, t_list *stack)
{
	t_list *tmp;
	tmp =stack;
	while (tmp)
	{
		if(tmp->number > num)
			return false;
		tmp = tmp->next;
	}
	return true;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}