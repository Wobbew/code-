/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_p.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/03 22:59:46 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/24 15:23:22 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_x(size_t num, char c)
{
	int		len;
	char	r;

	len = 0;
	if (num / 16 > 0)
	{
		len = ft_put_x(num / 16, c);
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

int	ft_put_p(size_t p)
{
	unsigned int	len;

	if (!p)
	{
		return (write(1, "(nil)", 5));
	}
	len = 0;
	len += ft_put_s("0x");
	len += ft_put_x(p, 'x');
	return (len);
}

// int main()
// {
// 	int num;
// 	num = -100;
// 	ft_printf("NULL: %p\n", NULL);

// 	// ft_printf("a%aa%a");
// 	//0x
// }