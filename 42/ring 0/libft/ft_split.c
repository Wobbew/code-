/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/16 22:33:17 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/29 22:14:58 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	wordcount(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

static void	free_split(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**fill(char const *s, char c, char **split)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (ft_wordlen(s, c) == 0)
			split[i] = NULL;
		else
		{
			split[i] = malloc((ft_wordlen(s, c) + 1) * sizeof(char));
			if (split[i] == NULL)
			{
				free_split(split, i);
				return (NULL);
			}
			ft_strlcpy(split[i], s, ft_wordlen(s, c) + 1);
		}
		s = s + ft_wordlen(s, c);
		i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (s == NULL)
		return (NULL);
	split = ft_calloc((wordcount(s, c)) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	return (fill(s, c, split));
}

// int	main(void)
// {
// 	char	**expected;
// 	int i;
// 	i = 0;
// 	expected = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
// 	if(!expected)
// 	{
// 		printf("null");
// 	}
// 	else
// 	{
// 		while( expected[i])
// 		{
// 			printf("%s\n", expected[i]);
// 			i ++;
// 		}
// 		printf("%s\n", expected[i]);
// 	}
// }
