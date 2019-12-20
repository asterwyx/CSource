#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

typedef struct node {
	Position element;
	struct node* previous;
	struct node* next;
} Node;

typedef struct queue {
	Node* front;
	Node* rear;
	int num;
} Queue;


void Init(Queue* q);

void Enqueue(Position e, Queue* q);

Position Dequeue(Queue* q);

int IsEmpty(Queue* q);

#endif