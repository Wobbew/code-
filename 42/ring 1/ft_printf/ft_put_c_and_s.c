/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c_and_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwiedijk <wwiedijk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:13:10 by wwiedijk          #+#    #+#             */
/*   Updated: 2025/11/02 13:58:45 by wwiedijk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
int ft_put_c(char c)
{
	write(1, &c, 1);
	return(1);
}

int ft_put_s(char *s)
{
	write(1, &s, ft_strlen(s));
	return(ft_strlen(s));
}
