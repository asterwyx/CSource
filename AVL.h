#ifndef _AVL_H
#define _AVL_H

typedef struct TreeNode {
	int value;
	struct TreeNode* left;
	struct TreeNode* right;
	int height;
} TreeNode;

typedef TreeNode* AVLTree;
typedef TreeNode* Position;

AVLTree Insert(int x, AVLTree head);
Position rotateWithLeft(Position k1);
Position rotateWithRight(Position k1);
Position doubleRotateWithLeft(Position k1);
Position doubleRotateWithRight(Position k1);
void PreOrderTraverse(const AVLTree tree);
void InOrderTraverse(const AVLTree tree);
void PostOrderTraverse(const AVLTree tree);
int Height(AVLTree head);




#endif
