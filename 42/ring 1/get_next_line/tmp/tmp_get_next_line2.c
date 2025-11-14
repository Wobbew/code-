/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp_get_next_line2.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/11 14:26:36 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/13 19:32:05 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_check_read(int i, char *buffer, char *str, char *tmp)
{
		if ((i < 0) || (i == 0 && !str) || (i == 0 && !buffer))
		{
			free(str);
			str = NULL;
			free(buffer);
			return (NULL);
		}
		if (i == 0 && (len(str, '\n') == -1 && len(str, '\0') == 0))
		{
			free(buffer);
			tmp = ft_substr(str, 0, len(str, '\0'));
			free(str);
			str = NULL;
			return (tmp);
		}
	((char *)buffer)[i] = '\0';
	return(buffer);
}

char *ft_read(int i, int fd, char *buffer, char *str, char *tmp)
{
	while (len(str, '\n') == -1 && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		tmp =ft_check_read(i, buffer, str, tmp);
		if (i == 0 && (len(str, '\n') == -1 && len(str, '\0') == 0))
			return(tmp);
		if (!buffer || buffer[0] == '\0')
			{
				free(tmp);
				return (NULL);
			}
		str = ft_strjoin(str, buffer);
		if (!str)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return(str);
}

char *check(char * str)
{
	if (!str)
		return(NULL);
	return(str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*next_line;
	char		*tmp;
	static char	*str = NULL;
	int			i;

	tmp = NULL;
	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if ((str= ft_read(i,fd, buffer,str, tmp)) == NULL || len(str, '\n') == -1)
		return(check(str));
	next_line = ft_substr(str, 0, len(str, '\n') + 1);
	if (!next_line)
		return (free(str), NULL);
	tmp = str;
	str = ft_substr(str, len(tmp, '\n') + 1, len(tmp + len(tmp, '\n') + 1,
				'\0'));
	free(tmp);
	if (!str)
		return (free(next_line), NULL);
	return (next_line);
}



