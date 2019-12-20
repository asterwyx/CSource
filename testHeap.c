#include "Heap.h"
#include <stdio.h>
#include <process.h>

#define MAX_SIZE 100
int main()
{
    int heapData[MAX_SIZE] = {0};
    int number = 0;
    printf("Please enter size, no greater than %d\n", MAX_SIZE);
    scanf("%d", &number);
    printf("Please enter the sequence\n");
    for (int i = 0; i < number; ++i)
    {
        scanf("%d", heapData + i); // 输入序列
    }
    printf("Build result is:\n");
	Heap heap = BuildHeap(heapData, number);
	for (int i = 1; i <= heap->size; i++)
	{
		printf("%d, ", heap->data[i]);
	}
	printf("\n");
	int sortLength = HeapSort(heap);
	printf("Sort result is:\n");
	for (int i = 1; i <= sortLength; i++)
	{
		printf("%d, ", heap->data[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}