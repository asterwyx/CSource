#ifndef _BST_H
#define _BST_H
#include<stdio.h>

typedef TreeNode *Child;
typedef TreeNode *SearchTree;
typedef struct TreeNode{
    int value;
    Child leftChild;
    Child rightChild;
} TreeNode;

#endif