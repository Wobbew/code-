   /* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/11 14:26:36 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/11 16:52:38 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_check_read(int i, char *buffer, char *str, char *tmp)
{
		if ((i < 0) || (i == 0 && !str))
		{
		free(str);
			str = NULL;
			free(buffer);
			return (NULL);
		}
		if (i == 0 && (len(str, '\n') == -1 || len(str, '\0') == 0))
		{
			free(buffer);
			tmp = ft_substr(str, 0, len(str, '\0'));
			free(str);
			str = NULL;
			
			return (tmp);
		}
	return(buffer);
}
char *ft_read(int i, int fd, char *buffer, char *str, char *tmp)
{
	while (len(str, '\n') == -1 && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer = ft_check_read(i, buffer, str, tmp);
		if (!buffer || buffer[0] == '\0')
			{
				free(tmp);
				return (NULL);
			}
		buffer[i] = '\0';
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

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*next_line;
	char		*tmp;
	static char	*str = NULL;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	str =ft_read(i, fd, buffer, str, tmp);
	if (!str)
		return(NULL);
	next_line = ft_substr(str, 0, len(str, '\n') + 1);
	if (!next_line)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	tmp = str;
	str = ft_substr(str, len(tmp, '\n') + 1, len(tmp + len(tmp, '\n') + 1,'\0'));
	free(tmp);
	if (!str)
	{
		free(next_line);
		return (NULL);
	}
	return (next_line);
}



