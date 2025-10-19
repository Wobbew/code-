/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/16 22:33:17 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/17 18:56:12 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*removec(char const *s, char c)
{
	while (*s == c && *s != '\0')
	{
		s++;
	}
	return ((char *)s);
}

int	wordcount(char const *s, char c)
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

int	ft_wordlen(char const *s, char c)
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

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	i = 0;
	split = malloc(wordcount(s, c) * sizeof(char *));
	while (s[i] != '\0')
	{
		s = removec(s, c);
		if (ft_wordlen(s, c) == 0)
		{
			split[i] = NULL;
		}
		else
		{
			split[i] = malloc((ft_wordlen(s, c) + 1) * sizeof(char));
			if (split[i] == NULL)
				return (NULL);
			ft_strlcpy(split[i], s, ft_wordlen(s, c));
		}
		s = s + ft_wordlen(s, c);
		i++;
	}
	return(split);
}

int	main()
{
	char	str[50] = "   ";
	char	**split;
	int i;
	char **(*f) ft_split();

	i = 0;
	split = ft_split(str, ' ');
	
	while (*split != NULL)
	{
		printf("%s\n", *split);
		split++;
	}
	printf("%s", *split);
	return (0);
}
