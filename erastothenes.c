#include<stdio.h>
#define N 50
int a[N] = {0};
void seekPrime(int n)
{
    if (a[i] == -1)
    {
        continue;  // a[i]已被标记说明i是之前经历的某一个i的倍数，那么现在的i的倍数也必然是之前i的倍数，也就是说现在ki位置已经全部被标记
    }
    for (int i = 2; i * i < n; i++)
    {
        for (int k = 2; k * i <= n; k++)
        {
            if (a[k * i] == -1)
            {
                continue;
            }
            a[k * i] = -1;
        }
    }
}

int main(int argc, char const *argv[])
{
    seekPrime(20);
    for (int i = 0; i < 20; i++)
    {
        if (a[i] != -1)
        {
            printf("%d\n", a[i]);
        }
    }
    return 0;
}
