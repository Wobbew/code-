/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 16:36:34 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/17 00:32:27 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int i)
{
	if (i == '\0')
		return (0);
	if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
		return (1);
	else
		return (0);
}
#include <stdio.h>
 int main(void)
 {
   int i;
   i = isalpha();
   printf("%d", i);
 }