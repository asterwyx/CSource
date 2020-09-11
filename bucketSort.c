#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void bucketSort(int array[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] >  max)
        {
            max = array[i];
        }
    }
    int *buckets = (int *)malloc((max + 1) * sizeof(int));
    

    // 入桶
    if (buckets)
    {
        memset(buckets, 0, (max + 1) * sizeof(int));
        for (int i = 0; i < n; i++)
        {
            buckets[array[i]]++;
        }        
    }
    else
    {
        return;
    }
    int i = 0, j = 0;

    // 倒桶
    do
    {
        if (buckets[i] == 0)
        {
            i++;
            continue;
        }
        else
        {
            array[j] = i;
            j++;
            buckets[i]--;
        }
        i++;
    } while (j < n);
}

int main(void)
{
    int a[10] = {1, 4, 9, 2, 5, 8, 3, 6, 7, 12};
    bucketSort(a, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", a[i]);
    }
    system("pause");
    return 0;
}
