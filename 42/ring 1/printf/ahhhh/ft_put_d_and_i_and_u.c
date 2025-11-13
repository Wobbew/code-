

#include "ft_printf.h"
int ft_put_d_and_i(int n)
{
	unsigned int	num;
	int len;

	len = 0;
	num = n;
	if (n < 0)
	{
		len += ft_put_c('-');
		num = -n;
	}
	if (num / 10 > 0)
	{
		len += ft_put_d_and_i(num / 10);
	}
	len += ft_put_c((num % 10) + '0');
	return(len);
}

int	ft_put_u(unsigned int n)
{
	int len;

	len = 0;
	if (n / 10 > 0)
	{
		len += ft_put_u(n / 10);
	}
	len += ft_put_c((n % 10) + '0');
	return(len);
}