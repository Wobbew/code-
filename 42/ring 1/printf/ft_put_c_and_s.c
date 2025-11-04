/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_c_and_s.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/30 12:13:10 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/04 15:46:02 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
int ft_put_c(char c)
{
	write(1, &c, 1);
	return(1);
}

int ft_put_s(char *s)
{
	if (!s)
	{
		return( write(1, "(null)", 6));
	}
	return(write(1, s, ft_strlen(s)));
}
