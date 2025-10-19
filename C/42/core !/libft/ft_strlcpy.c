/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 17:50:10 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/16 19:05:43 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (size == 0)
		return (ft_strlen(src));
	dst[size] = '\0';
	while (size > 0)
	{
		dst[size - 1] = src[size - 1];
		size--;
	}
	return (ft_strlen(src));
}
// #include <stdio.h>
// int main()
// {
// 	char src[50] = "wat is this";
// 	char dst[50] = "hi how are you";
// 	int i;
// 	i = ft_strlcpy(dst, src, 0);
// 	printf("%d:%s",i,dst);
// }
