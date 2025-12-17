/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/19 19:52:00 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/20 15:09:47 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
// 	t_list *head = NULL;
// 	t_list *newnode;
// 	int i;

// 	newnode = ft_lstnew("im");
// 	ft_lstadd_front(&head, newnode);
// 	newnode = ft_lstnew("hi,");
// 	ft_lstadd_front(&head, newnode);
// 	i = ft_lstsize(head);
// 	while (head)
// 	{
// 		printf("%s\t%d", (char *)head->content, i);
// 		head = head->next;
// 	}

// 	return (0);
// }