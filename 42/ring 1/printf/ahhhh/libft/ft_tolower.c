/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 14:00:50 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/13 23:11:23 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c += 32;
	}
	return (c);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	a;

// 	a = 'A';
// 	a = ft_tolower('S');
// 	printf("%c", a);
// }
