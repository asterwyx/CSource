#include<stdio.h>
#include<time.h>
unsigned int power(int x, int n)
{
    if (0 == n)
    {
        return (1);
    }
    if (n % 3 == 0)
    {
        return (power(x * x * x, n/3));
    }
    else if (n % 3 == 1)
    {
        return (x * power(x * x * x, n/3));
    }
    else
    {
        return (x * x * power(x * x * x, n/3));
    }
}

int main()
{
    int x = 2;
    int n = 3;
    clock_t start, end;
    for (; n <= 21; n += 2)
    {
        start = clock();
        for (int i = 0; i < 1000000; i++)
        {
          power(x, n);
        }
        end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("计算结果是:%12u\t", power(x, n));
        printf("执行时间是:%f\n", time);
    }
    return 0;
}
    
  
