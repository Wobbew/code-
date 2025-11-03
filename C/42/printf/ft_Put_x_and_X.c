#include <unistd.h>
#include <stdio.h>

int ft_put_x_X(unsigned int num, char c)
{
	int len;
	char R;

	len = 0;
	if (num / 16 > 0)
	{
		len = ft_put_x_X(num / 16, c);
	}
	num = num % 16;
	if (num < 10)
	{
		R =num + '0';
	}
	else
	{
		R = num + c - 33;
	}
	write(1, &R, 1);
	len++;
	return(len);
}

int main(int argc, char const *argv[])
{
	int i;
	i = -747385742;
	ft_put_x_X(i, 'x');
	printf("\n");
	printf("%x\n", i);
	return 0;
}
