/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwiedijk <wwiedijk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:28:06 by wwiedijk          #+#    #+#             */
/*   Updated: 2025/10/19 15:01:10 by wwiedijk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int i)
{
	if (i == '\0')
		return (0);
	if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
		return (1);
	else if (i >= 48 && i <= 57)
		return (1);
	else
		return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char* str = "sdsf";
// 	int i;
// 	i = isalnum(*str);
// 	printf("%d", i);
// }