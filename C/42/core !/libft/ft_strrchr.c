/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 14:41:55 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/13 23:03:19 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
		{
			return ((char *)s + i);
		}
		i--;
	}
	return (NULL);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[50] = "hi, ow are you doing";

// 	printf("%s", ft_strchr(str, 'o'));
// 	return (0);
// }
