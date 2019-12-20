#include "Heap.h"
#include <stdlib.h>

Heap BuildHeap(element_t* elements, int n)
{
	Heap heap = (Heap)malloc(sizeof(struct heap));
	if (heap == NULL)
	{
		perror("Out of space!!!");
		return NULL;
	}
	else
	{
		// 初始化堆，拷贝数据
		InitHeap(heap, CAPACITY + 1);
		for (int i = 0; i < n; i++)
		{
			heap->data[i + 1] = elements[i];
		}
		heap->size = n;
		// 调整至堆序
		for (int i = heap->size; i > 0; i--)
		{
			PercolateDown(heap, i);
		}
		return heap;
	}
}

void InitHeap(Heap heap, int capacity)
{
	if (heap == NULL)
	{
		perror("Out of space!!!");
		return;
	}
	heap->capacity = capacity;
	heap->data = (element_t*)malloc((capacity + 1) * sizeof(element_t));
	if (heap->data == NULL)
	{
		perror("Out of space!!!");
		return;
	}
	else
	{
		for (int i = 0; i <= capacity; i++)
		{
			heap->data[i] = NAELE;
		}
		heap->size = 0;
	}
}

void Insert(Heap heap, element_t element)
{
	int i;
	if (heap->size == heap->capacity) /* heap full */
		return;
	/* last element : h-> elements [h-> size – 1]
	parent of element i: i/2 */
	for (i = ++heap->size; i > 1
		&& heap->data[i / 2] > element; i /= 2)
		heap->data[i] = heap->data[i / 2];
	heap->data[i] = element;
}

// 采用使用最后一个元素填充的方法，下滤
element_t DeleteMax(Heap heap)
{
	if (heap->size == 0)
	{
		return NAELE;
	}
	element_t result = heap->data[1];
	element_t last = heap->data[heap->size];
	heap->data[heap->size--] = NAELE;
	int i, j;
	for (i = 1; 2 * i <= heap->size; i = j)
	{

		j = 2 * i;
		if (j != heap->size && heap->data[j + 1] > heap->data[j])
		{
			j++;
		}
		if (last >= heap->data[j])
		{
			break;
		}
		heap->data[i] = heap->data[j];
	}
	heap->data[i] = last;
	/*
	for (; i < heap->size; i++)
	{
		heap->data[i] = heap->data[i + 1];
	}
	*/
	
	return result;
}

void PercolateDown(Heap heap, int i)
{
	element_t tmp;
	int j, k;
	for (j = i, tmp = heap->data[j]; j * 2 <= heap->size; j = k)
	{
		/* find the smaller child */
		k = heap->data[2 * j] > heap->data[2 * j + 1] ? 2 * j : 2 * j + 1;
		/* if the root is bigger , move child one layer up */
		if (tmp < heap->data[k])
			heap->data[j] = heap->data[k];
		else
			break;
	}
	heap->data[j] = tmp;
}

int HeapSort(Heap heap)
{
	int tmp, size = heap->size;
	while (heap->size > 0)
	{
		tmp = DeleteMax(heap);
		heap->data[heap->size + 1] = tmp;
	}
	return size;
}