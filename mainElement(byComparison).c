#include<stdio.h>
#include<time.h>
#define MAX_LENGTH 100

int mainEle(int a[], int length)
{
    int tmp[MAX_LENGTH][2] = {0};
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (tmp[j][0] == a[i])
            {
                tmp[j][1]++;
                break;
            }
            else
            {
                if (j = count - 1)
                {
                    tmp[count][0] = a[i];
                    count++;
                }
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        if (tmp[i][1] > (length / 2))
        {
            return tmp[i][0];
        }
        
    }
    return (-1);
}

int main()
{
    clock_t start, end;
    for (int n = 10; n <= 100; n += 10)
    {   
        int test[] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
                  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                  4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
        start = clock();
        for (int i = 0; i < 1000000; i++)
        {
            mainEle(test, n);
        }
        end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("计算结果是:%d\t", mainEle(test, n));
        printf("%f\n", time);
    }
    return 0;
}