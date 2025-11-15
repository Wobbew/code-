/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wobbe <wobbe@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/11 14:26:36 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/15 15:21:02 by wobbe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	int		i;
	char	*read_return;

	i = 1;
	read_return = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!read_return)
		return (free(str), NULL);
	while (ft_strchr(str, '\n') == NULL)
	{
		i = read(fd, read_return, BUFFER_SIZE);
		if (i < 0)
			return (free(str), free(read_return), NULL);
		if (i == 0)
		{
			break ;
		}
		read_return[i] = 0;
		str = ft_strjoin(str, read_return);
		if (!str)
			break ;
	}
	return (free(read_return), str);
}

char	*ft_line(char *str)
{
	char	*tmp;
	int		size;
	int		i;
	char	*newline_pos;

	i = 0;
	newline_pos = ft_strchr(str, '\n');
	if (newline_pos)
		size = newline_pos - str + 1;
	else
		size = ft_strlen(str);
	tmp = malloc((size + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (i < size)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_next_line(char *str)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (str[size] != '\n' && str[size] != '\0')
		size++;
	if (str[size] == '\0')
		return (free(str), NULL);
	size++;
	while (str[size + i] != '\0')
	{
		str[i] = str[size + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char			*return_line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	next_line = ft_read(fd, next_line);
	if (!next_line)
		return (NULL);
	if (next_line[0] == '\0')
	{
		free(next_line);
		next_line = NULL;
		return (NULL);
	}
	return_line = ft_line(next_line);
	if (!return_line) 
	{
		free(next_line);
		next_line = NULL;
		return (NULL);
	}
	next_line = ft_next_line(next_line);
	return (return_line);
}


