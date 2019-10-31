#include<stdio.h>
#include<stdlib.h>
#include<time.h>
unsigned int power(int x, int n)
{
    if (0 == n)
    {
        return 1;
    }
    
    int remds = n % 2;
    if (0 == remds)
    {
        return power(x * x, n/2);  // 这里的传参细节十分重要
    }
    else
    {
        return (x * power(x * x, n/2));
    }    
}

int main()
{
    int x = 2;  // 计算的是2的幂
    int n = 2;  // n初始为5000
    clock_t start, end;
    
    for (; n <= 20; n += 2)
    {
        start = clock();
        for (int i = 0; i < 1000000; i++)
        {
            power(x, n);
        }
        end = clock();
        printf("计算结果是:%12u\t", power(x, n));
        double time = (double) (end - start) / CLOCKS_PER_SEC;
        printf("执行时间为:%f\n", time);    
    }
    return (0);
}