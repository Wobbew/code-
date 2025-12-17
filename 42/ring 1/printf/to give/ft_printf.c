/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/24 15:01:03 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/24 16:41:33 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static int	ft_format(const char c, va_list arg)
{
	int	num;

	num = 0;
	if (c == 'c')
		num = ft_put_c(va_arg(arg, int));
	else if (c == 's')
		num = ft_put_s(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		num = ft_put_d_and_i(va_arg(arg, int));
	else if (c == 'x' || c == 'X')
		num = ft_put_x_x(va_arg(arg, unsigned int), c);
	else if (c == 'u')
		num = ft_put_u(va_arg(arg, unsigned int));
	else if (c == 'p')
		num = ft_put_p(va_arg(arg, size_t));
	else if (c == '%')
		num = ft_put_c('%');
	return (num);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		num;

	if (!format)
		return (-1);
	va_start(args, format);
	num = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(format + 1) == 0)
				return(-1);
			num += ft_format(*(format + 1), args);
			format++;
		}
		else
			num += ft_put_c(*format);
		format++;
	}
	va_end(args);
	return (num);
}

// int main()
// {
// 	int num;
// 	num = -100;
// 	printf("%d\n", ft_printf("%%%%%%%%%%%%%%%"));
// 	printf("%d\n", printf("%%%%%%%%%%%%%%%"));

// 	// ft_printf("a%aa%a");
// 	//0x
// }