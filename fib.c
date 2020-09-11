#include <stdio.h>

int fib(int n);

int main()
{
	
	printf("%d", fib(10));
	return (0);
}

int fib(int n)
{
	int tmp1 = 1;
	int tmp2 = 1;
	int result = 0;
	if (n < 3)
	{
		return (1);
	}
	
	while (--n >= 2)
	{
		result = tmp1 + tmp2;
		tmp1 = tmp2;
		tmp2 = result;
	}
	return result;
}
