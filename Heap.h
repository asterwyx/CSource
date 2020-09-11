#ifndef _HEAP_H
#define CAPACITY 100
#define NAELE -100000
typedef int element_t;


typedef struct heap {
	int capacity;
	int size;
	element_t* data;
}* Heap;




Heap BuildHeap(element_t* elements, int n);
void InitHeap(Heap heap, int capacity);
void Insert(Heap heap, element_t element);
element_t DeleteMax(Heap heap);
void PercolateDown(Heap heap, int i);
int HeapSort(Heap heap);
#endif // !_HEAP_H
