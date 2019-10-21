#include <stdio.h>
void insSort(int *a, int n)
{
    int i, j, key;
    for (i = 0; i < n; i++)
    {
        key = a[i];
        for (j = i - 1; j >= 0 && a[j] > key; j--)
        {
            a[j+1] = a[j];
            a[j] = key;
        }
    }
    
}

int main()
{
    int array[10] = {1,5,43,87,23,90,45,67,89,95};
    for (int i = 0; i < 10; i++)
    {
        printf("%d, ", array[i]);
    }
    insSort(array, 10);
    printf("\nThis is a divider...\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d, ", array[i]);
    }
}