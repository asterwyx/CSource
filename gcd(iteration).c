#include <stdio.h>
int gcd(int m, int n)
{
    int tmp;
    int counter = 0;
    while (n != 0)
    {
        tmp = n;
        m = n;
        n = tmp % n;
        counter++;
    }
    return counter;
}

// 测试主程序
int main()
{
    int result;
    result = gcd(21, 13);
    printf("%d\n", result);
    return 0;
}
