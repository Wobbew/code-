/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 21:00:12 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/13 23:08:20 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	num;
	int	i;
	int	plusorminus;

	num = 0;
	i = 0;
	plusorminus = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		i++;
		if (nptr[i] == '-')
			plusorminus = -1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num *= 10;
		num += nptr[i] - 48;
		i++;
	}
	return (num * plusorminus);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	src[50] = "\v\n \r\f \t-452146";

// 	printf("%d", atoi(src));
// }
