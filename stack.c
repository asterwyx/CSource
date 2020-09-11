#include "stack.h"

// 堆栈的一系列例程
Node makeStack() {
    Node head = {0, (Node *)NULL};
    return head;
}


status push(Node *head, int data) {
    Node *new;

    if (NULL == head) {
        printf("Invalid list head\n");
        return ERROR;
    }
    new = (Node *) malloc(sizeof(Node));
    if (NULL == new) {
        printf("malloc()failed, cannot push a new value\n");
        return ERROR;
    }
    new->data = data;
    new->next = head->next;
    head->next = new;
    return SUCCESS;
}

int pop(Node *head, int *value) {
    Node *ptr;

    if (NULL == head) {
        printf("Invalid list head\n");
	return ERROR;
    }

    if (NULL == head->next) {
        printf("Stack is empty\n");
        return ERROR;
    }

    *value = head->next->data;
    ptr = head;
    head = head->next;
    free(ptr);
    return SUCCESS;
}
