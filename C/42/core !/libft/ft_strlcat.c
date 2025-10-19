/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/08 17:31:08 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/17 16:33:09 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	if (size < ft_strlen(dst))
// 		return (ft_strlen(src) + size);
// 	ft_memcpy(dst + ft_strlen(dst), src, size - ft_strlen(dst) - 1);
// 	dst[size - 1] = '\0';
// 	return (ft_strlen(dst) + ft_strlen(src));
// }

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	sizeofdst;
	int	sizeofsrc;
	int	i;

	i = 0;
	sizeofdst = ft_strlen(dst);
	sizeofsrc = ft_strlen(src);
	if (size < sizeofdst)
		return (sizeofsrc + size);
	while (src[i] != '\0' && sizeofdst + 1 < size)
	{
		dst[sizeofdst + i] = src[i];
		i++;
		size--;
	}
	dst[sizeofdst + i] = '\0';
	return (sizeofdst + sizeofsrc);
}
#include <stdio.h>
int main()
{
	char dst[15] = "hiewd ";
	char str[20] =  "im wobberee";
	int i;
	i = ft_strlcat(dst, str, 20);
	printf("%d:%s",i,dst);
	return (0);
}
