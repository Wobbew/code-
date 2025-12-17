/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/19 16:50:12 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/28 15:58:46 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
// 	t_list *head = NULL;
// 	t_list *newnode;

// 	newnode = ft_lstnew("im");
// 	ft_lstadd_front(&head, newnode);
// 	newnode = ft_lstnew("hi,");
// 	ft_lstadd_front(&head, newnode);
// 	while (head)
// 	{
// 		printf("%s", (char *)head->content);
// 		head = head->next;
// 	}

// 	return (0);
// }
