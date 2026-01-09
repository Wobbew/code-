#include "Pushswap.h"
int main(int argc, char const *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (check_args(argc, argv) == 1)
		return (free_all(&stack_a, &stack_b), 1);
	if(make_stack(&stack_a, argc, argv))
		return (free_all(&stack_a, &stack_b), 1); 
	sort(&stack_a, &stack_b);
	// PB(&stack_a, &stack_b);
	// PB(&stack_a, &stack_b);
	// print_stack(stack_a);
	// print_stack(stack_b);
	// RRR(&stack_a, &stack_b);
	// print_stack(stack_a);
	// print_stack(stack_b);

	return 0;
}
