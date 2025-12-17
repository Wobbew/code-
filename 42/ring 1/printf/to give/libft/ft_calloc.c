/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/13 13:42:02 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/03 18:16:57 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t number, size_t size)
{
	void	*mem;

	if (size == 0 || number == 0)
	{
		return (malloc(0));
	}
	if (number > SIZE_MAX / size)
	{
		return (NULL);
	}
	mem = malloc(number * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, number * size);
	return (mem);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*array;
// 	int	size;
// 	int	i;

// 	size = 7;
// 	i = 0;
// 	array = calloc("", 0);
// 	if(array == NULL)
// 	{
// 		printf("1");
// 	}
// 	printf("%s", array);
// // 	while (i < size)
// // 	{
// // 		printf("%c\n", array[i]);
// // 		i++;
// // 	}
// // 	free(array);
// }
