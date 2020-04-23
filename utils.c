#include <stdio.h>
#include <stdlib.h>

double f(double x)
{
    return ((2 * x + 1) / (1 + x * x * x * x));
}


double Part2(int m)
{
    double result = 0;
    for (int i = 0; i < m / 4; i++)
    {
        result += (1 / (double)m) * f((2 * (double)i + 1) / ((double)m / 2));
    }
    return result;
}

int main()
{
    double result = Part2(4);
    printf("%f\n", result);
    result = Part2(8);
    printf("%f\n", result);
    result = Part2(16);
    printf("%f\n", result);
    result = Part2(32);
    printf("%f\n", result);
    result = Part2(64);
    printf("%f\n", result);
    system("pause");
    return 0;
}