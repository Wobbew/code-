/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wobbe <wobbe@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/05 17:53:27 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/12 17:35:28 by wobbe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct s_list
{
	char			*next_line;
	char			*str;
	char			*buffer;
	char			*tmp;
}					t_list;
char		*get_next_line(int fd);
long int	len(char *s, char c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s, unsigned int start, size_t l);



char	*ft_strjoin2(t_list *storage);
#endif
