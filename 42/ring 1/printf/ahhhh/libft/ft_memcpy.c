/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 14:02:50 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/28 15:58:00 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmpd;
	const char	*tmps;

	if (dest == NULL && src == NULL)
		return (NULL);
	tmpd = dest;
	tmps = src;
	while (n > 0)
	{
		*tmpd = *tmps;
		tmpd++;
		tmps++;
		n--;
	}
	return (dest);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char tmpd[1000] = "im wobbe";
// 	char tmps[1000] = "hi";
// 	char tmp[100];

// 	printf ("%s", memcpy(tmpd, tmps, NULL));

// }