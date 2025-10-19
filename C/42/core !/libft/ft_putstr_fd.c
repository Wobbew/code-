/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/16 23:50:32 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/17 01:30:07 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
void ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int main(int argc, char const *argv[])
{
	ft_putstr_fd("hiee", 1);
	return 0;
}
