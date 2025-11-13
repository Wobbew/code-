
#include "get_next_line.h"

char *read_error( char *buffer, char *str)
{
	free(str);
	buffer = NULL;
	free(buffer);
	return(NULL);
}



char *ft_read( int fd, char *buffer, char *str)
{
	int i;

	i = 1;
	while (len(str, '\n') == -1 && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if ((i < 0) || (i == 0 && !str))
			return(read_error(buffer, str));
		if(i = 0)
		{
			free(buffer);
			ft_substr(str, 0, len(str, '\0'));
			free(str);
			str = NULL;
			if (!buffer || buffer[0] == '\0')
			{
				return (free(buffer), NULL);
			}
		}
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
		printf("buffer after strjoin: %s\n", str);
		if (!buffer)
			return (free(buffer),NULL);
	}
	return(buffer);
}
char	*get_next_line(int fd)
{
	char		*buffer;
	char		*next_line;
	char		*tmp;
	static char	*str = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	str =ft_read(fd, buffer, str);
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

