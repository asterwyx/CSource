#include "queue.h"
void Init(Queue *q)
{
    q->front = (Node *)malloc(sizeof(Node));
    q->front = NULL;
    q->rear = q->front;
    q->num = 0;
}

void Enqueue(int e, Queue *q)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode)
    {
        newNode->element = e;
        newNode->next = q->front->next;
        if (q->front->next != NULL)
        {
            q->front->next->previous = newNode;
        }
        else
        {
            q->rear = newNode;
        }
        q->front->next = newNode;
        newNode->previous = q->front;
    }
}

int Dequeue(Queue *q)
{
    if (q->rear == q->front)
    {
        return ;
    }
    int result = q->rear->element;
    q->rear = q->rear->previous;
    free(q->rear->next);
    q->rear->next = NULL;
    return result;
}