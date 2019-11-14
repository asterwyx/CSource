#include <stdio.h>
#define INFIY 1024
#define MIN(x,y) (x) > (y) ? (y) : (x)
int min(int a, int b, int c)
{
    return MIN(MIN(a, b), c);
}

int change(int n)
{
    if (n < 0)
    {
        return INFIY;
    }
    else if (n == 0)
    {
        return 0;
    }

    return (1 + min(change(n - 1), change(n - 3), change(n - 7)));    
}

int main()
{
    printf("result is:%d", change(12));
    system("pause");
    return 0;
}