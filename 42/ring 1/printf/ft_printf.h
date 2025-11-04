/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/02 13:09:52 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/11/04 14:33:41 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *, ...);
int	ft_put_c(char c);
int	ft_put_s(char *s);
int ft_put_d_and_i(int n);
int	ft_put_u(unsigned int n);
int ft_put_p(unsigned long p);
int ft_put_x_X(unsigned int num, char c);
#endif