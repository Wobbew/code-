/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/08 16:53:54 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/14 18:30:47 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (((unsigned char *)s)[i] != '\0' && i < n)
	{
		if (((unsigned char *)s)[i] == c)
		{
			return (((void *)(unsigned char *)s + i));
		}
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str[50] = "hi, how are you doing";

// 	printf("%s", (char *)ft_memchr(str, 'o', 3));
// 	return (0);
// }
