/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/14 15:46:24 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/16 20:18:16 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(const char *s)
{
	char	*newstr;

	newstr = malloc(ft_strlen(s) * sizeof(char));
	ft_strlcpy(newstr, s, ft_strlen(s));
	return (newstr);
}

// #include <stdio.h>

// int	main(int argc, char const *argv[])
// {
// 	char	*dup;

// 	dup = ft_strdup("12345");
// 	printf("%s", dup);
// 	return (0);
// }
