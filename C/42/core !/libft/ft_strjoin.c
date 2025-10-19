/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/15 18:52:16 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/16 19:27:55 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;

	newstr = malloc(ft_strlen(s1) + ft_strlen(s2) * sizeof(char));
	if (!newstr)
	{
		return (NULL);
	}
	ft_strlcpy(newstr, s1, ft_strlen(s1));
	ft_strlcpy(newstr + ft_strlen(s1), s2, ft_strlen(s2));
	return (newstr);
}

int	main(int argc, char const *argv[])
{
	char	str1[10] = "12345";
	char	str2[10] = "12345";
	char	*newstr;

	newstr = ft_strjoin(str1, str2);
	printf("%s", newstr);
	free(newstr);
	return (0);
}
