/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/14 18:25:19 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/16 19:04:07 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (ft_strlen(s + start) > len)
	{
		sub = malloc(len * sizeof(char));
		if (!sub)
			return (NULL);
		ft_strlcpy(sub, s + start, len);
	}
	else
	{
		sub = malloc(ft_strlen(s + start) * sizeof(char));
		if (!sub)
			return (NULL);
		ft_strlcpy(sub, s + start, ft_strlen(s + start));
	}
	return (sub);
}

// #include <stdio.h>
// int main()
// {
// 	char *sub;
// 	char str[10] = "123456789";
// 	sub =ft_substr(str, 6, 2);
// 	printf("%s", sub);
// 	free(sub);
// 	return (0);
// }
