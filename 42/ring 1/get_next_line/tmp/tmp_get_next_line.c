/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp_get_next_line.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/11 14:26:36 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/13 16:36:56 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_line(int i, int fd, char *buffer, char *str, char *tmp)
{
	i = 1;
	while (len(str, '\n') == -1 && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if ((i < 0) || (i == 0 && !str))
		{
			free(str);
			str = NULL;
			return (free(buffer),NULL);
		}
		if (i == 0 && (len(str, '\n') == -1 || len(str, '\0') == 0))
		{
			tmp = ft_substr(str, 0, len(str, '\0'));
			free(str);
			str = NULL;
			if (!tmp || ((char *)tmp)[0] == '\0')
				return (free(buffer),free(tmp),NULL);
			return (free(buffer),tmp);
		}
		((char *)buffer)[i] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (free(buffer), NULL);
	}
	return(free(buffer), str);
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
	str = ft_read_line(i,fd, buffer,str, tmp);
	if (str == NULL)
		return(NULL);
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


