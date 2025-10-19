/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 14:16:15 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/13 23:11:36 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c -= 32;
	}
	return (c);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char a = 'z';
// 	a = ft_toupper('a');
// 	printf("%c", a);
// }