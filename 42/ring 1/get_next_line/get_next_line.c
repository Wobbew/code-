/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/05 17:45:17 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/07 14:37:46 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || !fd)
		return (NULL);
	char		uitput[BUFFER_SIZE];
	char		*next_line;
	char		*tmp;
	static char	*str = NULL;
	int			i;

	i = 0;
	while (len(str, '\n') == -1 || len(str, '\0') == 0)
	{
		i = read(fd, uitput, BUFFER_SIZE);
		if (i == 0 && !str)
			return (NULL);
		if (i == 0&& (len(str, '\n') == -1 || len(str, '\0') == 0))
		{
			tmp = ft_substr(str, 0, len(str, '\0'));
			free(str);
			str = NULL;
			return (tmp);
		}
		if (i < BUFFER_SIZE)
			uitput[i] = '\0';
		str = ft_strjoin(str, uitput);
	}
	next_line = ft_substr(str, 0, len(str, '\n') + 1);
	tmp = ft_substr(str, len(str, '\n') + 1, len(str + len(str, '\n'), '\0'));
	free(str);
	str = ft_substr(tmp, 0, len(tmp, '\0'));
	free(tmp); 
	return (next_line);
}

// char *get_next_line(int fd)
// {
// 	static char *str = NULL;
// 	char BUFFER;
// 	read(fd, uitput, BUFFER_SIZE);

// // }

// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	fd = open("file.txt", O_RDONLY);
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s); // free(line);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);

// 	close(fd);
// 	return (0);
// }
