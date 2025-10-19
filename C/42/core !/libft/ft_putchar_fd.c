/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/16 23:37:42 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/17 01:16:35 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main(int argc, char const *argv[])
// {
// 	ft_putchar_fd('t', 1);
// 	return 0;
// }
