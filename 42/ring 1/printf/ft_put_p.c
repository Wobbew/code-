/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_p.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/03 22:59:46 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/04 15:55:51 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

 int ft_put_x(size_t num, char c)
{
	int len;
	char R;

	len = 0;
	if (num / 16 > 0)
	{
		len = ft_put_x(num / 16, c);
	}
	num = num % 16;
	if (num < 10)
	{
		R =num + '0';
	}
	else
	{
		R = num + c - 33;
	}
	write(1, &R, 1);
	len++;
	return(len);
}

int ft_put_p(size_t p)
{
	unsigned int len;
	if (!p)
	{
		return( write(1, "(nil)", 5));
	}
	len = 0;
	len += ft_put_c('0');
	len += ft_put_c('x');
	len += ft_put_x(p, 'x');
	return(len);
}

// int main()
// {
// 	int num;
// 	num = -100;
// 	ft_printf("NULL: %p\n", NULL);
	
// 	// ft_printf("a%aa%a");
// 	//0x
// } 