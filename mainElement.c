#include<stdio.h>
#include<time.h>

int mainEle(int a[], int length)
{
    int tmpLength;
    while (length != 0 && length != 1)
    {
        tmpLength = 0;
        if (length % 2 == 1)
        {
            for (int i = 0; i < length - 1; i += 2)
            {
                if (a[i] == a[i + 1])
                {
                    a[tmpLength] = a[i];
                    tmpLength++;
                }
            } 
            a[tmpLength] = a[length - 1];
            length = tmpLength + 1;
        }
        else
        {
            for (int i = 0; i < length; i += 2)
            {
                if (a[i] == a[i + 1])
                {
                    a[tmpLength] = a[i];
                    tmpLength++;
                }
            }
            length = tmpLength; 
        }
        
    }
    if (length == 0)
    {
        return (-1);
    }
    else
    {
        return a[0];
    }
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
    