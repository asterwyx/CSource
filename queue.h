#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int element;
    struct node *previous;
    struct node *next;
} Node;

typedef struct queue{
    Node *front;
    Node *rear;
    int num;
} Queue;


void Init(Queue *q);

void Enqueue(int e, Queue *q);

int Dequeue(Queue *q);


#endif