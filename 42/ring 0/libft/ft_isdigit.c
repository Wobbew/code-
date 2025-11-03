/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 17:41:32 by wwiedijk      #+#    #+#                 */
/*   Updated: 2025/10/29 18:04:41 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int i)
{
	if (i == '\0')
		return (0);
	if (i >= 48 && i <= 57)
		return (1);
	else
		return (0);
}
// #include <stdio.h>
//  int main(void)
//  {
//    int i;
//    i = ft_isdigit('1');
//    printf("%d", i);
//  }