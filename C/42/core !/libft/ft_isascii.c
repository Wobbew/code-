/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 18:33:22 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/13 21:43:46 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int i)
{
	if (i >= 0 && i <= 127)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
//  int main(void)
//  {
//    int i;
//    i = ft_isascii('€');
//    printf("%d", i);
//  }