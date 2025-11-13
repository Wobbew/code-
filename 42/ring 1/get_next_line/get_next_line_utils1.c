/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils1.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wobbe <wobbe@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/05 17:55:18 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/12 17:47:14 by wobbe         ########   odam.nl         */
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

char	*ft_filljoin2(t_list *storage, char *newstr)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (len(storage->buffer, '\0') == -1)
		return (NULL);
	if (storage->str != NULL)
	{
		while (storage->str[i])
		{
			newstr[i] = storage->str[i];
			i++;
		}
	}
	while (storage->buffer[j])
	{
		newstr[i + j] = storage->buffer[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}

char	*ft_strjoin2(t_list *storage)
{
	char	*newstr;
	long int s1_len;
	long int s2_len;
	s1_len = len(storage->str, '\0');
	s2_len = len(storage->buffer, '\0');
	if (s2_len == -1)
		return (NULL);
	newstr = malloc((s1_len + s2_len + 1) * sizeof(char));

	if (!newstr)
	{
		free(storage->str);
		free(storage->buffer);
		return (NULL);
	}
	newstr = ft_filljoin2(storage, newstr);
	return (free(storage->str), newstr);
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
	{
		
		return (NULL);
	}
	while (s[start + i] && l > i)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

