/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/14 18:25:19 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/23 18:30:53 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen(s + start) > len)
	{
		sub = malloc((len + 1) * sizeof(char));
		if (!sub)
			return (NULL);
		ft_strlcpy(sub, s + start, len + 1);
	}
	else
	{
		sub = malloc((ft_strlen(s + start) + 1) * sizeof(char));
		if (!sub)
			return (NULL);
		ft_strlcpy(sub, s + start, ft_strlen(s + start) + 1);
	}
	return (sub);
}

// #include <stdio.h>
// #include <strings.h>

// int	main(void)
// {
// 	char	*sub;
// 	char	str[10] = "123456789";

// 	sub = ft_substr(str, 0, 1000);
// 	printf("%s", sub);
// 	free(sub);
// 	return (0);
// }
