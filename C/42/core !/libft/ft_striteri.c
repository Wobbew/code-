

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int 	i;
	t_list test;
	i = 0;
	while (s[i] != '\0')
	{
	 f(i, s+i);
		i++;
	}
}



// void to_upper(unsigned int i, char *c)
// {


// 	if (*c >= 'a' && *c <= 'z')
// 	{
// 		*c -= 32;
// 	}

// }
// int main(int argc, char const *argv[])
// {
	
// 	char str[] = "wAs55saSfwA";
// 	ft_striteri(str, to_upper);
// 	printf("%s", str);
// 	return 0;
// }
