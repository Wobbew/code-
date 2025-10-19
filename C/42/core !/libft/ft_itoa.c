/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/15 19:27:13 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/17 00:52:00 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_intlen(long unsigned int n)
{
	int	length;

	length = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		length++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		neg;
	unsigned int ntmp;

	neg = 0;
	ntmp = n;
	num = ft_calloc(ft_intlen(ntmp), sizeof(char));
	if (num == NULL)
		return (NULL);
	if (ntmp == 0)
	{
		num[0] = '0';
		return (num);
	}
	if (n < 0)
	{
		num[0] = '-';
		neg = 1;
	}
	while (ntmp > 0)
	{
		num[ft_intlen(ntmp) - 1 + neg] = ((ntmp % 10) + 48);
		ntmp = ntmp / 10;
	}
	return (num);
}

int	main(void)
{
	char	*num;

	num = ft_itoa(-2147483648);
	printf("%s", num);
	return (0);
}
