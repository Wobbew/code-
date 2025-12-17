/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/15 18:52:16 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/21 01:56:30 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;

	newstr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstr)
	{
		return (NULL);
	}
	ft_strlcpy(newstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(newstr, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	return (newstr);
}

// int	main(void)
// {
// 	char	str1[10] = "144434";
// 	char	str2[10] = "12345";
// 	char	*newstr;

// 	newstr = ft_strjoin(str1, str2);
// 	printf("%s", newstr);
// 	free(newstr);
// 	return (0);
// }

// void	ft_print_result(char const *s)
// {
// 	int		len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }
