/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 21:00:12 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/23 01:02:45 by wwiedijk      ########   odam.nl         */
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
		if (nptr[i] == '-')
			plusorminus = -1;
		i++;
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
// 	printf("'1456' : %d\n", ft_atoi("1456");
// 	printf("'-1456' : %d\n", ft_atoi("-1456");
// 	printf("'   +1456' : %d\n", ft_atoi("   +1456");
// 	printf("'   +-+1456' : %d\n", ft_atoi("   +-+1456");
// 	printf("' y  +-+1456' : %d\n", ft_atoi(" y  +-+1456");
// 	printf("'   145o6' : %d\n", ft_atoi("   145o6"));
// 	printf("'o' : %d\n ", ft_atoi("o"));
// }
