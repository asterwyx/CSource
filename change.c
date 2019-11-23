#include <stdio.h>
#define INFIY 1024
#define MIN(x,y) (x) > (y) ? (y) : (x)
int min(int a, int b, int c)
{
    return MIN(MIN(a, b), c);
}

int c[1024] = {0};
int d[] = {1, 3, 7};

int DP_Change(int n)
{
    int tmp, i, j;
    for (i = 0, c[0] = 0; i <= n; i++)
    {
        tmp = INFIY;
        for (j = 0; j < 3; j++)
        {
            if (d[j] <= i && c[i - d[j]] + 1 < tmp)
            {
                tmp = c[i - d[j]] + 1;
            }
        }
        c[i] = tmp;
    }
    return (c[n]);
}

// int change(int n)
// {
//     if (n < 0)
//     {
//         return INFIY;
//     }
//     else if (n == 0)
//     {
//         return 0;
//     }

//     return (1 + min(change(n - 1), change(n - 3), change(n - 7)));    
// }

int main()
{
    printf("result is:%d", DP_Change(100));
    system("pause");
    return 0;
}