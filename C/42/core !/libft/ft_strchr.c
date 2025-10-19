/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 14:18:59 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/13 23:10:41 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[50] = "hi, how are you doing";

// 	printf("%s", ft_strchr(str, 'e'));
// 	return (0);
// }
