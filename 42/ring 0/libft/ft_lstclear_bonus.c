/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/22 16:34:28 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/22 21:44:14 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

// void	ft_del(void *content)
// {
// 	(void)content;
// }

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (*lst != NULL)
	{
		ft_lstclear(&(*lst)->next, del);
		del((*lst)->content);
	}
	free(*lst);
	*lst = NULL;
}

// int main(void)
// {
//     t_list *head = NULL;
//     t_list *cur;

// 	t_list *node1 = ft_lstnew("first");
// 	t_list *node2 = ft_lstnew("3");
// 	t_list *node3 = ft_lstnew("third");

// 	ft_lstadd_back(&head, node1);
// 	ft_lstadd_back(&head, node2);
// 	ft_lstadd_back(&head, node3);

//     printf("List contents:\n");
//     cur = head;
//     while (cur)
//     {
//         printf("%s\n", (char *)cur->content);
//         cur = cur->next;
//     }

//     printf("\nClearing list...\n");

//     ft_lstclear(&node2, ft_del);
//     cur = head;
//     while (cur != NULL)
//     {
//         printf("%s\n", (char *)cur->content);
//         cur = cur->next;
//     }
//     if (head == NULL)
//         printf("Success! Head is now NULL\n");
//     else
//         printf("Error: Head is not NULL\n");

//     return (0);
// }
