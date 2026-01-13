/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wwiedijk <wwiedijk@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/13 19:57:04 by wwiedijk      #+#    #+#                 */
/*   Updated: 2026/01/13 19:57:05 by wwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

int	main(int argc, char const *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (check_args(argc, argv) == 1)
		return (free_all(&stack_a, &stack_b), 1);
	if (make_stack(&stack_a, argc, argv))
		return (free_all(&stack_a, &stack_b), 1);
	sort(&stack_a, &stack_b);
	return (0);
}
