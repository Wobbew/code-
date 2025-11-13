
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

static	int ft_format(const char c, va_list arg)
{
	int num;
	num = 0;
	if (c == 'c')
		num =ft_put_c(va_arg(arg, int));
	else if (c == 's')
		num =ft_put_s(va_arg(arg, char*));
	else if (c == 'd' || c == 'i')
		num =ft_put_d_and_i(va_arg(arg, int));
	else if (c == 'x' || c == 'X')
		num = ft_put_x_X(va_arg(arg, unsigned int), c);
	else if (c == 'u')
		num = ft_put_u(va_arg(arg, unsigned int));
	else if (c == 'p')
		num = ft_put_p(va_arg(arg, size_t));
	else if (c == '%')
		num =ft_put_c('%');
	return(num);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int num;

	if (!format )
	{
		return(-1);
	}
	num = 0;
	while(*format != '\0')
	{
		if (*format == '%')
		{
			num += ft_format(*(format + 1), args);
			format++;
			num --;
		}
		else
			ft_put_c(*format);
		num++;
		format++;
	}
	va_end(args);
	return(num);
}


// int main()
// {
// 	int num;
// 	num = -100;
// 	printf("%d\n", ft_printf("%%%c%%%s%%%s", 'a', "hi", "ne"));
// 	printf("%d\n", printf("%%%c%%%s%%%s", 'a', "hi", "ne"));
	
// 	// ft_printf("a%aa%a");
// 	//0x
// } 