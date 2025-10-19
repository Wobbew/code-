/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 18:47:37 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/17 00:16:11 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int i)
{
	if (i == '\0')
		return (0);
	if (i >= 32 && i <= 126)
		return (1);
	else
		return (0);
}
#include <stdio.h>
 int main(void)
 {
   int i;
   i = isprint('y');
   printf("%d", i);
 }