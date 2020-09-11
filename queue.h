#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
typedef int element_t;

typedef struct node {
	element_t element;
	struct node* previous;
	struct node* next;
} Node;

typedef struct queue {
	Node* front;
	Node* rear;
	int num;
} Queue;


void Init(Queue* q);

void Enqueue(element_t e, Queue* q);

element_t Dequeue(Queue* q);

int IsEmpty(Queue* q);

#endif