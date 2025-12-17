/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: wobbe <wobbe@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/05 17:55:18 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/15 15:12:30 by wobbe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;

	i = 0;
	newstr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstr)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2 && *s2)
	{
		newstr[i] = *s2;
		s2++;
		i++;
	}
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}

char	*ft_strchr( char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*newstr;

	i = 0;
	newstr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!newstr)
	{
		return (free(s), NULL);
	}
	while (s[i] != '\0')
	{
		newstr[i] = s[i];
		i++;
	}
	free(s);
	return (newstr);
}
