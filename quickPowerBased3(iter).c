#include<stdio.h>
int pow(int x, int n)
{
    int res = 1;
    if (0 == n)
    {
        return (1);
    }
    for (; n >= 0; n / 3)
    {
        if (n % 3 == 1)
        {
            res *= x;
        }
        else if (n % 3 == 2)
        {
            res *= x * x;
        }
        x = x * x * x;
    }
    return res;
}