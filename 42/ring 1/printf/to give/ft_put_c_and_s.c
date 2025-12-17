/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_c_and_s.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/24 15:09:49 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/24 15:25:14 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_put_c(char c)
{
	return (write(1, &c, 1)); 
}

int	ft_put_s(char *s)
{
	if (!s)
		s = "(null)";
	return (write(1, s, ft_strlen(s)));
}
