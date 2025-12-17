#include "Pushswap.h"
int check_args(int argc, char const *argv[])
{
	if (argc < 2)
	{
		write(2, "Error\n", 7);
		return (1);
	}
	if(argc == 2 && argv[1][0] == '\0')
	{
		write(2, "Error\n", 7);
		return (1);
	}
	return (0);
}