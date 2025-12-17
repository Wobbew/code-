/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_Put_x_and_X.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/24 14:59:37 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/24 15:13:18 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	ft_put_x_x(unsigned int num, char c)
{
	int		len;
	char	r;

	len = 0;
	if (num / 16 > 0)
	{
		len = ft_put_x_x(num / 16, c);
	}
	num = num % 16;
	if (num < 10)
	{
		r = num + '0';
	}
	else
	{
		r = num + c - 33;
	}
	write(1, &r, 1);
	len++;
	return (len);
}
