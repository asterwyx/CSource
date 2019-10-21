#include<stdio.h>
void quickSort(int list[], int start, int end)
{
    if (start >= end)
    {
        return ;
    }

    int tmp;
    int low = start;
    int high = end;


    while (low < high)
    {
        while (list[high] >= list[start] && high > low)
        {
            high--;
        }
        while (list[low] <= list[start] && high > low)
        {
            low++;
        }
        
        tmp = list[low];
        list[low] = list[high];
        list[high] = tmp;
    }

    tmp = list[low];
    list[low] = list[start];
    list[start] = tmp;
    
    // 分治
    quickSort(list, start, low-1);
    quickSort(list, high+1, end);
}


int main()
{
    int testArray[10] = {45, 7, 97, 34, 554, 345, 32, 34, 65, 78};
    quickSort(testArray, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", testArray[i]);
    }
    
    return 0;
}