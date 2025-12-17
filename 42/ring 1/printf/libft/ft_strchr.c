/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 14:18:59 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/22 23:55:14 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[50] = "hi, how are you doing";

// 	printf("%s", ft_strchr(str, '\0'));
// 	return (0);
// }
