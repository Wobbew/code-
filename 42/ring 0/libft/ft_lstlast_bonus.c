/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/19 20:07:42 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/20 15:09:38 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main(void)
// {

//     t_list *n1 = ft_lstnew("first");
//     t_list *n2 = ft_lstnew("second");
//     t_list *n3 = ft_lstnew("third");

//     // Link the nodes
//     n1->next = n2;
//     n2->next = n3;

//     // Call ft_lstlast
//     t_list *last = ft_lstlast(n1);

//     // Print result
//     if (last && last->content)
//         printf("Last node content: %s\n", (char *)last->content);
//     else
//         printf("List is empty or error occurred.\n");

//     // Free memory
//     free(n1);
//     free(n2);
//     free(n3);

//     return (0);
// }
