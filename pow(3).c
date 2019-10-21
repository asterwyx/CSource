#include<stdio.h>
int pow(int x, int n)
{
    if (0 == n)
    {
        return (1);
    }
    if (n % 3 == 0)
    {
        return (pow(x * x * x, n/3));
    }
    else if (n % 3 == 1)
    {
        return (x * pow(x * x * x, n/3));
    }
    else
    {
        return (x * x * pow(x * x * x, n/3));
    }
}