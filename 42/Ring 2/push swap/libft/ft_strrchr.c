/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 14:41:55 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/22 23:52:16 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
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
// char str_real4[50];
// 	strcpy(str_real4, "Hello 42 ! ! 24 olleH");
// 	char *pos_real2 = strrchr(str_real4, 'o');
// 	char *pos_test2 = ft_strrchr(str_real4, 'o');
// 	printf("str : %s\n strrchr : %s\n real : %s\n", str_real4, pos_test2,
// pos_real2);
// 	return (0);
// }
