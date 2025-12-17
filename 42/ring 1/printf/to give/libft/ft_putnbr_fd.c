/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/17 00:43:37 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/20 15:10:54 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = -n;
	}
	if (num / 10 > 0)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	ft_putchar_fd((num % 10) + '0', fd);
}
// int main(int argc, char const *argv[])
// {
// 	ft_putnbr_fd(-155521, 1);
// 	return (0);
// }
