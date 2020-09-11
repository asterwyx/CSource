#include "queue.h"

void Init(Queue* q)
{
	q->front = (Node*)malloc(sizeof(Node));
	if (q->front != NULL)
	{
		q->front->next = NULL;
		q->rear = q->front;
		q->num = 0;
	}
	else
	{
		perror("Out of space!!");
		exit(EXIT_FAILURE);
	}
}

void Enqueue(element_t e, Queue* q)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL)
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
		q->num++;
	}
}

element_t Dequeue(Queue* q)
{
	if (q->rear == q->front)
	{
		return 0;
	}
	element_t result = q->rear->element;
	q->rear = q->rear->previous;
	q->num--;
	free(q->rear->next);
	q->rear->next = NULL;
	return result;
}

int IsEmpty(Queue* q)
{
	if (q->num == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
