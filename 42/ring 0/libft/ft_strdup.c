/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/14 15:46:24 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/23 00:16:28 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*newstr;

	newstr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!newstr)
	{
		return (NULL);
	}
	ft_strlcpy(newstr, s, ft_strlen(s) + 1);
	return (newstr);
}

// #include <stdio.h>

// int	main(int argc, char const *argv[])
// {
// 	char	*dup;

// 	dup = ft_strdup("12345544567");
// 	printf("%s", dup);
// 	return (0);
// }
