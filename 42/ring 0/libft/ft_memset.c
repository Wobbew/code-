/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 18:57:00 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/20 19:16:58 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <unistd.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	while (n > 0)
	{
		*((unsigned char *)s + n - 1) = (unsigned char)c;
		n--;
	}
	return (s);
}

// #include <string.h>

// int	main(void)
// {
// 	unsigned char buffer[10] = "111111111";
// 	// ft_memset(buffer, ' ', 5);
// 	ft_memset(buffer +2, 's', 3);
// 	// memset(NULL, 'e', 2);

// 	printf("%s", buffer);
// }