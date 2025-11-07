/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/05 17:55:18 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/07 14:31:21 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long int	len(char *s, char c)
{
	long int	i;

	if ((!s) && (c == '\0'))
		return (0);
	if (!s)
		return (-1);
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			return (i);
		}
		i++;
	}
	if (c == 0)
		return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	newstr = malloc((len(s1, '\0') + len(s2, '\0') + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i])
		{
			newstr[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	free(s1);
	return (newstr);
}

char	*ft_substr(char *s, unsigned int start, size_t l)
{
	char	*sub;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (len(s + start, '\0') < (long int)l)
		l = len(s + start, '\0');
	sub = malloc((l + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (s[start + i] && l > i)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
