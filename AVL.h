#ifndef _AVL_H
#define _AVL_H
typedef TreeNode *AVLTree;
typedef TreeNode *Position;
AVLTree Insert(int x, AVLTree head);
Position rotateWithLeftChild(Position k1);
Position rotateWithRightChild(Position k1);
Position doubleRotateWithLeftChild(Position k1);
Position doubleRotateWithRightChild(Position k1);
void PreOrderTraverse(const AVLTree tree);
void InOrderTraverse(const AVLTree tree);
void PostOrderTraverse(const AVLTree tree);
void AVLTreeBFS(const AVLTree tree);
int Height(AVLTree head);


typedef struct TreeNode {
    int value;
    Position left;
    Position right;
    int height;
} TreeNode;

#endif
