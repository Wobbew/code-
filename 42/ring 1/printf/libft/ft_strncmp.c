/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 14:47:52 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/20 15:47:06 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char)s1[i] != '\0'
			|| (unsigned char)s2[i] != '\0'))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	printf("(\"abcdef\",\"ABCDEF\", 2):%d\n",ft_strncmp("abcdef", "ABCDEF", 2));
// 	printf("(\"abcdef\",\"ABCDEF\", 2):%d\n",strncmp("abcdef", "ABCDEF", 2));
// 	printf("(\"abcdef\",\"abcdef\", 2):%d\n",ft_strncmp("abcdef", "abcdef",2));
// 	printf("(\"abcdef\",\"abcdef\", 2):%d\n",strncmp("abcdef", "abcdef",2));
// 	printf("(\"abcdef\",\"abcdey\", 5):%d\n",ft_strncmp("abcdef", "abcdey",5));
// 	printf("(\"abcdef\",\"abcdey\", 6):%d\n",ft_strncmp("abcdef", "abcdey",6));
// 	printf("(\"\\200\",\"\\0\", 6): %d\n", ft_strncmp("\200", "\0", 6));
// }
