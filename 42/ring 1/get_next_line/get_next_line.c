
#include "get_next_line.h"
char	*get_next_line(int fd)
{
	char		*buffer;
	char		*next_line;
	char		*tmp;
	static char	*str = NULL;
	int			i;
	
	// Check fd BEFORE allocating
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);

	i = 1;
	while (len(str, '\n') == -1 && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)  
		{
			free(buffer);
			return (NULL);
		}
		if (i == 0 && !str)
		{
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
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);  
	
	next_line = ft_substr(str, 0, len(str, '\n') + 1);
	if (!next_line)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	tmp = str;
	str = ft_substr(str, len(tmp, '\n') + 1, len(tmp + len(tmp, '\n') + 1, '\0'));
	free(tmp);
	if (!str)
	{
		free(next_line);
		return (NULL);
	}
	// if (next_line[0] == '\n' && next_line[1] == '\0')
	// {
	// 	free(next_line);
	// 	next_line = NULL;
	// 	return (NULL);
	// }
	return (next_line);
}

