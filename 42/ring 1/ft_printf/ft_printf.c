
#include <stdio.h>
#include <stdarg.h>
#include "libftprintf.h"

static	int ft_format(const char c, va_list arg)
{
	int num;

	num = 0;
	if (c == 'c')
	{
		num =ft_put_c(va_arg(arg, int));
	}
	else if (c == 's')
	{
		num =ft_put_s(va_arg(arg, char*));
	}
	else if (c == 'd')
	{
		
	}
	return(num);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int num;

	num = 0;
	while(*format != '\0')
	{
	if (*format == '%')
	{
		num += ft_format(*format + 1, args);
		num --;
	}
	num++;
	format++;
	}
	return(num);
}


int main()
{
	int num;
	num = 10;

// With %d - only accepts decimal
// scanf("%d", &num);  
// // Input: 012  → stores as 12 (not 10)
// // Input: 0x10 → stops at 'x', stores 0

// // With %i - auto-detects base
// scanf("%i", &num);  
// Input: 012  → stores as 10 (octal)
// Input: 0x10 → stores as 16 (hex)
// Input: 10   → stores as 10 (decimal)
	int a;
	a =32;
	printf("%p", &num);
	// ft_printf("a%aa%a");
	//0x
} 