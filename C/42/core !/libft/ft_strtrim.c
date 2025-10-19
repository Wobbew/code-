/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/15 20:01:20 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/17 18:46:14 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #include <stdbool.h> 

int	isinset(char c, char const *set )
{
	bool	r ;
	int j;
	
	j =0;
	r =false;
	while (j < ft_strlen(set))
		{
			if (c == set[j])
			{
				r = true;
			}
			j++;
	
		}	
	return(r);
}
char	*ft_strtrim(char const *s1, char const *set)
{
int i;
	int j;
	int size;
	char	*trimmedstr;

	size = ft_strlen(s1);
	i =0;
	j =ft_strlen(s1);
	while (isinset(s1[i], set) && size >i)
		i++;
	while (isinset(s1[j], set) && j > 0)
		j--;
	((char *)s1)[j] = '\0';
	trimmedstr = ft_strdup(s1+i);
	if (trimmedstr == NULL)
	{
		
	}
	
}

// int trimed(char  *s1, char const *set)
// {
// 	int i;
// 	int j;
// 	int size;
// 	char	*trimmedstr;

// 	size = ft_strlen(s1);
// 	i =0;
// 	j =ft_strlen(s1);
// 	while (isinset(s1[i], set, size) && size >i)
// 		i++;
// 	while (isinset(s1[j], set,size))
// 		j--;
// 	s1[j] = '\0';
// 	trimmedstr = ft_strdup(s1+i);
// }


// int	ft_beginning(char const *s1, char const *set)
// {
// 	int	i;
// 	int	j;
// 	int	stop;

// 	stop = 0;
// 	i = 0;
// 	while (s1[i] != '\0' && stop != 1)
// 	{
// 		stop = 1;
// 		j = 0;
// 		while (j < ft_strlen(set))
// 		{
// 			if (s1[i] == set[j])
// 			{
// 				stop = 0;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (i - 2);
// }

// int	ft_end(char const *s1, char const *set)
// {
// 	int	i;
// 	int	j;
// 	int	stop;

// 	stop = 0;
// 	i = ft_strlen(s1) - 1;
// 	while (stop != 1)
// 	{
// 		stop = 1;
// 		j = 0;
// 		while (j < ft_strlen(set))
// 		{
// 			if (s1[i] == set[j])
// 			{
// 				stop = 0;
// 			}
// 			j++;
// 		}
// 		i--;
// 	}
// 	return (ft_strlen(s1) - (i + 2));
// }

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	char	*trimmedstr;
// 	int		len;
	
// 	len = ft_strlen(s1 + ft_beginning(s1, set)) - ft_end(s1, set);
// 	trimmedstr = malloc(len* sizeof(char));
// 	if (trimmedstr == NULL)
// 	{
// 		return(NULL);
// 	}
// 	ft_strlcpy(trimmedstr, s1 + ft_beginning(s1, set) + 1, len);
// 	trimmedstr[len - 1] = '\0';
// 	return(trimmedstr);
// }

int	main(int argc, char const *argv[])
{
	char *trimmedstr;
	trimmedstr =ft_strtrim("r", "-+");
	printf("%s",trimmedstr);
	return (0);
}
