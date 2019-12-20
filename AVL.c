#include "AVL.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX(a, b) (a) > (b) ? a : b

Position rotateWithLeft(Position k1)
{
    Position k2 = k1->left;
    k1->left = k2->right;
    k2->right = k1;
    k1->height = MAX(Height(k1->left), Height(k1->right)) + 1;
    k2->height = MAX(Height(k2->left), Height(k2->right)) + 1;
    return k2;
}

Position rotateWithRight(Position k1)
{
    Position k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = MAX(Height(k1->left), Height(k1->right)) + 1;
    k2->height = MAX(Height(k2->left), Height(k2->right)) + 1;    
    return k2;
}

Position doubleRotateWithLeft(Position k1)
{
    k1->left = rotateWithRight(k1->left);
    return rotateWithLeft(k1);
}

Position doubleRotateWithRight(Position k1)
{
    k1->right = rotateWithLeft(k1->right);
    return rotateWithRight(k1);
}


AVLTree Insert(int x, AVLTree head)
{
    if (head == NULL)
    {
        // 真正的插入在这里发生
        head = (Position)malloc(sizeof(TreeNode));
        if (head == NULL)
        {
            printf("Out of space!!!");
        }
        else
        {
            // 设置新分配的结点
            head->value = x;
            head->left = NULL;
            head->right = NULL;
            head->height = 0;
        }
        
    }
    else if (x < head->value)
    {
        // 连接在这里发生
        head->left = Insert(x, head->left);
        // 判断平衡是否被破坏以及怎么样被破坏，如果被破坏，调整平衡
        if ((Height(head->left) - Height(head->right)) > 1)
        {
            if (x < head->left->value)
            {
                head = rotateWithLeft(head);
            }
            else
            {
                head = doubleRotateWithLeft(head);
            }
        }    
    }
    else if (x > head->value)
    {
        head->right = Insert(x, head->right);
        // 判断平衡是否被破坏以及怎么样被破坏，如果被破坏，调整平衡
        if ((Height(head->right) - Height(head->left)) > 1)
        {
            if (x > head->right->value)
            {
                head = rotateWithRight(head);
            }
            else
            {
                head = doubleRotateWithRight(head);
            }
        }
    }
	head->height = MAX(Height(head->left), Height(head->right)) + 1;
    return head;
}

int Height(AVLTree head)
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        return head->height;
    }
}

void PreOrderTraverse(const AVLTree tree) 
{
	if (tree == NULL)
	{
		return;
	}

	printf("%d ", tree->value);
	PreOrderTraverse(tree->left);
	PreOrderTraverse(tree->right);
}

void InOrderTraverse(const AVLTree tree)
{
	if (tree == NULL)
	{
		return;
	}

	InOrderTraverse(tree->left);
	printf("%d ", tree->value);
	InOrderTraverse(tree->right);

}

void PostOrderTraverse(const AVLTree tree)
{
	if (tree == NULL)
	{
		return;
	}

	PostOrderTraverse(tree->left);
	PostOrderTraverse(tree->right);
	printf("%d ", tree->value);
}
