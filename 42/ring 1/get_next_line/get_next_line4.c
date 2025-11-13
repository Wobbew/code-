
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wobbe <wobbe@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/11 14:26:36 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/12 17:16:38 by wobbe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*storage;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	storage->buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!storage->buffer)
		return (NULL);
	i = 1;
	while (len(storage->str, '\n') == -1 && i > 0)
	{
		i = read(fd, storage->buffer, BUFFER_SIZE);
		if ((i < 0) || (i == 0 && !storage->str))
		{
			free(storage->str);
			storage->str = NULL;
			free(storage->buffer);
			return (NULL);
		}
		if (i == 0 && (len(storage->str, '\n') == -1 || len(storage->str, '\0') == 0))
		{
			free(storage->buffer);
			storage->tmp = ft_substr(storage->str, 0, len(storage->str, '\0'));
			free(storage->str);
			storage->str = NULL;
			if (!storage->tmp || storage->tmp[0] == '\0')
			{
				free(storage->tmp);
				return (NULL);
			}
			return (storage->tmp);
		}
		storage->buffer[i] = '\0';
		storage->str = ft_strjoin2(storage);
		if (!storage->str)
		{
			free(storage->buffer);
			return (NULL);
		}
	}
	free(storage->buffer);
	storage->next_line = ft_substr(storage->str, 0, len(storage->str, '\n') + 1);
	if (!storage->next_line)
	{
		free(storage->str);
		storage->str = NULL;
		return (NULL);
	}
	storage->tmp = storage->str;
	storage->str = ft_substr(storage->str, len(storage->tmp, '\n') + 1, len(storage->tmp + len(storage->tmp, '\n') + 1,
				'\0'));
	free(storage->tmp);
	if (!storage->str)
	{
		free(storage->next_line);
		return (NULL);
	}
	return (storage->next_line);
}

