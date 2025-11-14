/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/11 14:26:36 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/14 20:11:08 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return(0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int i;

	i =0;
	newstr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstr)
		return (free(s1),free(s2), NULL);
	while (s1 && s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2 && *s2)
	{
		newstr[i] = *s2;
		s2++;
		i++;
	}
	newstr[i] = '\0';
	// free(s1);
	// free(s2);
	return (newstr);
}

char	*ft_strchr( char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return(NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}
char	*ft_strdup(char *s)
{
	int i;
	char	*newstr;

	i= 0;
	newstr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!newstr)
	{
		return (free(s), NULL);
	}
	while (s[i] != '\0')
	{
		newstr[i] = s[i];
		i++;
	}
	
	// free(s);
	return (newstr);
}

char	*ft_read(int fd, char *str)
{
	int	i;

	char *read_return;
	i = 1;
	read_return = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!read_return)
		return(free(str), NULL);
	while (ft_strchr(str, '\n') == NULL)
	{
		i = read(fd, read_return, BUFFER_SIZE);
		if (i < 0)
			return (free(str), free(read_return), NULL);
		// printf("read_\t|%s|\n", ft_strchr(str, '\n'));
		if (i == 0)
		{
			break ;
		}
		read_return[i+1] = 0;
		str = ft_strjoin(str, read_return);
		// printf("%s", str);
	}
	// printf("ahhh\t\t%s",str);
	return (str);
}
char *ft_next_line(char *str)
{
	int size;
	int i;

	size = 0;
	i =0;
	while (str[size] != '\n' && str[size] != '\0')
		size ++;
	if(str[size] == '\0')
		return(NULL);
	size++;
	while (str[size + i] != '\0')
	{
		str[i] = str[size +i];
		i++;
	}
	str[i] = '\0';
	return(str);
}
char *ft_line(char *str)
{
	char *tmp;
	int size;
	int i;
	size = ft_strlen(str) -ft_strlen(ft_strchr(str, '\n'));
	tmp = malloc((size +1) * sizeof(char)); 
	i = 0;
	if (!tmp)
		return(NULL);
	while (i <= size)
	{
		tmp[i] = str[i];
		i++;
	}
	return(tmp);
}
char	*get_next_line(int fd)
{
	static char	*next_line ;
	char *Return;
		// printf("\t%s",next_line);
	if (BUFFER_SIZE < 0 || fd < 0 || fd > 1024)
		return(NULL);
	next_line = ft_read(fd, next_line);
	// printf("\t\n%s",next_line);
	if (!next_line)
		return(NULL);
	Return = ft_line(next_line);
	next_line = ft_next_line(next_line);
	// printf("|%s|\n",next_line);
	return(Return);
}


