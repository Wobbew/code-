/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwiedijk <wwiedijk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:09:52 by wwiedijk          #+#    #+#             */
/*   Updated: 2025/11/02 14:07:11 by wwiedijk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *, ...);
int	ft_put_c(char c);
int	ft_put_s(char *s);

#endif