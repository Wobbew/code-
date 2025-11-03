
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i;
	int j;
	void *t = "awe";
	i = 0xDEADBEE;
	j = -15;
	printf("%p\n", &i);
	return 0;
}
