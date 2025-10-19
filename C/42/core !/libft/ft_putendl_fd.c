/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/17 00:35:06 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/17 01:33:16 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
void ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

int main(int argc, char const *argv[])
{
	ft_putendl_fd("hiee", 1);
	return 0;
}