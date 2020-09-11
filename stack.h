#ifndef _STACK_H
#define _STACK_H
#define ERROR -1
#define SUCCESS 0
#define NULL 0

#include <stdio.h>

typedef int status;
typedef struct node {
    int data;
    struct node *next;
} Node;
Node makeStack();
status push(Node *head, int data);
status pop(Node *head, int *value);


#endif
