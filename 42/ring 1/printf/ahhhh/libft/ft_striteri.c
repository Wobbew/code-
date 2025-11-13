/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/19 14:58:20 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/20 21:08:10 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}

// void to_upper(unsigned int i, char *c)
// {

// 	if (*c >= 'a' && *c <= 'z')
// 	{
// 		*c -= 32;
// 	}

// }
// int main(int argc, char const *argv[])
// {

// 	char str[] = "wAs55saSfwA";
// 	ft_striteri(str, to_upper);
// 	printf("%s", str);
// 	return (0);
// }