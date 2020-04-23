#include <stdio.h>
int pow(int x, int n)
{
    int result = 1;
    if (0 == n) {
        return 1;
    }
    if (n % 2 == 1) {
        return pow(x, n / 2) * pow(x, n / 2) * x; // 这里两次调用递归是不恰当的，依然会有很多的重复计算
    }
    else
    {
        return pow(x, n / 2) * pow(x, n / 2);
    }
}

// 改进版
int power(int x, int n){
    int result = 1;
    if (0 == n) {
        return 1;
    }
    int tmp = power(x, n / 2);
    if (n % 2 == 1) {
        return tmp * tmp * x; // 这里两次调用递归是不恰当的，依然会有很多的重复计算
    }
    else
    {
        return tmp * tmp;
    }
}