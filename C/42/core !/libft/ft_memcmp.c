/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/08 16:57:18 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/13 23:06:33 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		{
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		}
		i++;
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char s1[50] = "hat";
// 	char s2[50] = "hat how are you";
// 	int i;
// 	i = ft_memcmp(s1, s2, 4);
// 	printf("%d", i);
// }