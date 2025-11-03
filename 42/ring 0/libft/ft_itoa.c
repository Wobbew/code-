/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/15 19:27:13 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/29 17:32:04 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_intlen(long int n)
{
	int	length;

	length = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n > 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

static char	*convert(unsigned int n, int neg, char *num)
{
	while (n > 0)
	{
		num[ft_intlen(n) - 1 + neg] = ((n % 10) + 48);
		n = n / 10;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		neg;
	long	ntmp;

	neg = 0;
	ntmp = n;
	if (n < 0)
	{
		ntmp *= -1;
		neg = 1;
	}
	num = (char *)ft_calloc(ft_intlen(ntmp) + 1 + neg, sizeof(char));
	if (num == NULL)
		return (NULL);
	if (ntmp == 0)
	{
		num[0] = '0';
		return (num);
	}
	if (n < 0)
		num[0] = '-';
	return (convert(ntmp, neg, num));
}

// int	main(void)
// {
// 	char	*res;

// 	res = ft_itoa(-2147483648LL);
// 	printf("%s", res);
// 	free(res);
// }
