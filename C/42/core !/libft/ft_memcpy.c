/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 14:02:50 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/16 19:07:02 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n > 0)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		dest++;
		src++;
		n--;
	}
	return (dest);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	unsigned char src[] = "hi im wobbe";
// 	unsigned char dest[20] = "are we all alone";
// 	// memcpy(dest, src, 60);
// 	ft_memcpy(dest, src, 60);
// 	printf("%s", dest);
// }