/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/15 20:01:20 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/29 17:32:57 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	isinset(char c, char const *set)
{
	bool	r;
	size_t	j;

	j = 0;
	r = false;
	while (j < ft_strlen(set))
	{
		if (c == set[j])
		{
			r = true;
		}
		j++;
	}
	return (r);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*trimmedstr;

	if (s1 == NULL || set == NULL)
		return (NULL);
	size = ft_strlen(s1);
	i = 0;
	j = ft_strlen(s1);
	while (isinset(s1[i], set) && size > i)
		i++;
	while (isinset(s1[j - 1], set) && j > i)
		j--;
	trimmedstr = malloc(j - i + 1);
	if (trimmedstr == NULL)
		return (NULL);
	ft_strlcpy(trimmedstr, s1 + i, j - i + 1);
	trimmedstr[j - i + 1] = '\0';
	return (trimmedstr);
}

// int	main(int argc, char const *argv[])
// {
// 	char *trimmedstr;
// 	trimmedstr =ft_strtrim("---44---", "-+");
// 	printf("%s",trimmedstr);
// 	return (0);
// }
