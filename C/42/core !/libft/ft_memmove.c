/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 17:19:14 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/15 23:43:56 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>
#include <unistd.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	if (dest < src)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (n > 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	return (dest);
}
// #include <stdio.h>

// int	main(void)
// {
// 	unsigned char src[228] = "12345";
// 	unsigned char *dest;
// 	dest = src;
// 	// memcpy(src +2, src, 15);
// 	// memmove(dest, src+2, 15);
// 	// ft_memmove(dest , src +2  , 15);
// 	// printf("addres of dest%p\n", dest);
// 	// 	printf("addres of src%p\n", src+5);
// 	// printf("%s", (char *)ft_memmove(dest , src +2, 15));
// 	memmove(NULL+2, src , 6);
// 	printf("%s", dest);
// 	// ft_memmove(NULL , src +2, 3);
// 	// printf("%s", dest);
// }