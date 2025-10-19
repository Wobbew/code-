

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int 	i;
	char *newstr;

	i = 0;
	if (!s || !f)
		return (NULL);
	newstr = malloc(sizeof(char) * ft_strlen(s));
	if (!newstr)
		return(NULL);
	while (s[i] != '\0')
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	return(newstr);
}



// char my_func(unsigned int i, char c)
// {
//     return c + i;
// }
// int main(int argc, char const *argv[])
// {

// 	void *f = &my_func;
// 	char *res;
// 	res = ft_strmapi("111111111", f);
// 	printf("%s\n", res);
// 	return 0;
// }
