#include <stdio.h>

double h(int n)
{
	if(0 == n)
		return (1.0);
	return (1.0 + 1.0/h(n-1));
}


int main(int argc, char *argv)
{
	double result;
	int depth;
	scanf("%d", &depth);
	result = h(depth) - 1.0;
	printf("%f", result);
	return 0;
}

	