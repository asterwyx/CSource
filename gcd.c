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

int main()
{
    
}