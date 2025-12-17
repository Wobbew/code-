/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/08 16:53:54 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/22 16:30:39 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == (unsigned char)c)
		{
			return ((void *)tmp + i);
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
// 	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
//   printf("%s", (char *)ft_memchr(tab, -1, 7));

// 	// printf("%s", (char *)ft_memchr(str, 'o', 3));
// 	return (0);
// }
