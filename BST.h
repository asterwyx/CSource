#ifndef _BST_H
#define _BST_H
#include<stdio.h>

typedef TreeNode *Child;
typedef TreeNode *SearchTree;
typedef struct TreeNode{
    int value;
    Child leftChild;
    Child rightChild;
    int height;  // 写AVL的时候使用，记录该树的高度
} TreeNode;

SearchTree insert(int element, SearchTree head);
SearchTree delete(int element, SearchTree head);

#endif
