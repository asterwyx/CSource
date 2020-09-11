#include <stdio.h>
int pow(int x, int n)
{
    if (0 == n)
    {
        return 1;
    }
    int result = 1;
    for (; n > 0; n = n >> 1) {
        if (n % 2 == 1) {
            result *= x;
        }
        x *= x;
    }
    return result;
}
