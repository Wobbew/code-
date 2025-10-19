/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 16:05:50 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/13 23:01:35 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
// #include <stdio.h>
// int main(void)
// {
//   size_t i;
//   int array[] = {1, 2, 3, 4, 5,};
//   i = ft_strlen(array);
//    printf("%ld", i);
// }
