#include<stdio.h>
double pow(double x, int n)
{
    if (0 == n)
    {
        return 1;
    }
    
    int remds = n % 2;
    if (0 == remds)
    {
        return pow(x * x, n/2);  // 这里的传参细节十分重要
    }
    else
    {
        return (x * pow(x * x, n/2));
    }    
}