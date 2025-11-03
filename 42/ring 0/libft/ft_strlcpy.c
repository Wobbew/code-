/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 17:50:10 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/20 19:43:04 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (size - 1 > i && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	src_real2[] = "";
// 	char	dest_real2[1];
// 	char	dest_test2[1];
// 	int		src_real2_s;
// 	int		src_test2_s;

// 	src_test2_s = ft_strlcpy(dest_test2, src_real2, 5);
// 	src_real2_s = strlcpy(dest_real2, src_real2, 5);

// 	printf("Test : Copied '%s' into '%s', length %d\n", src_real2, dest_test2,
// 		src_test2_s);
// }
