/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/22 16:35:37 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/29 22:43:01 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	content = f(lst->content);
	new_list = ft_lstnew(content);
	if (!new_list)
		return (del(content), NULL);
	lst = lst->next;
	while (lst)
	{
		content = f(lst->content);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, tmp);
		lst = lst->next;
	}
	return (new_list);
}

// void	ft_del(void *content)
// {
// 	(void)content;
// }
// void	*transform_to_upper(void *content)
// {
// 	char	*str;
// 	char	*new_str;
// 	int		i;

// 	str = (char *)content;
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (((char *)content)[i])
// 	{
// 		if (((char *)content)[i] >= 'a' && ((char *)content)[i] <= 'z')
// 			((char *)content)[i] -= 32;
// 		i++;
// 	}
// 	return (content);
// }

// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char const *argv[])
// {
// 	t_list *head = NULL;
// 	t_list *node1 = ft_lstnew("first");
// 	t_list *node2 = ft_lstnew("3");
// 	t_list *node3 = ft_lstnew("third");

// 	ft_lstadd_back(&head, node1);
// 	ft_lstadd_back(&head, node2);
// 	ft_lstadd_back(&head, node3);

// 	t_list *cur = ft_lstmap(head, transform_to_upper, ft_del);
// 	while (cur)
// 	{
// 		printf("%s\n", cur->content);
// 		cur = cur->next;
// 	}
//     return (0);
// }
