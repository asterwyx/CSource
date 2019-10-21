#include<stdio.h>
#include<time.h>
int sum(int n)
{   
    int tmp = 0;

    for (int i = 1; i <= n; i++)
    {
        tmp += i * i;
    }

    return tmp;
}

int main()
{
    int test = 0;
    scanf("%d", &test);
    int result = 0;
    clock_t start, end;
    start = clock();
    result = sum(test);
    end = clock();
    double seconds = (double)(end - start)/CLOCKS_PER_SEC;
    printf("%f", seconds);
    return 0;
}