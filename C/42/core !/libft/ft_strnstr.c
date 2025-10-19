/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 16:45:24 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/13 23:06:00 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	big_loc;
	int	little_loc;

	big_loc = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big_loc < len && big[big_loc] != '\0')
	{
		little_loc = 0;
		while (big[big_loc] == little[little_loc])
		{
			if (little[little_loc + 1] == '\0')
				return ((char *)big + big_loc - little_loc);
			big_loc++;
			little_loc++;
		}
		big_loc = big_loc - little_loc + 1;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	big[] = "hi, i hope it will work";
// 	char	little[] = "it";

// 	printf("%s", ft_strnstr(big, little, 100));
// }
