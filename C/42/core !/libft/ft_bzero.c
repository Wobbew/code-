/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 13:34:44 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/17 15:22:36 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;

	tmp = s;
	while (n)
	{
		*tmp = '0';
		n--;
		tmp++;
	}
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//    char bufffer[10] = "12674356";
//    ft_bzero(bufffer, 6);
// 	printf("%s", bufffer);
// }