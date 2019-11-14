#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
void radixSort(int array[], int n)
{
    return ;
}

int main(void)
{
    int test[10] = {42, 46, 87, 98, 23, 45, 67, 8, 0, 6};
    Queue *q[10];
    for (int i = 0; i < 10; i++)
    {
        q[i] = (Queue *)malloc(sizeof(Queue));
        Init(q[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        Enqueue(test[i], q);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", Dequeue(q));
    }
    
    return 0;
}