#include "AVL.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "queue.h"

#define MAX(a, b) (a) > (b) ? a : b

Position rotateWithleft(Position k1)
{
    Position k2 = k1->left;
    k1->left = k2->right;
    k2->right = k1;
    k1->height = MAX(Height(k1->left), Height(k1->right)) + 1;
    k2->height = MAX(Height(k2->left), Height(k2->right)) + 1;
    return k2;
}

Position rotateWithright(Position k1)
{
    Position k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = MAX(Height(k1->left), Height(k1->right)) + 1;
    k2->height = MAX(Height(k2->left), Height(k2->right)) + 1;    
    return k2;
}

Position doubleRotateWithleft(Position k1)
{
    k1->left = rotateWithright(k1->left);
    return rotateWithleft(k1);
}

Position doubleRotateWithright(Position k1)
{
    k1->right = rotateWithleft(k1->right);
    return rotateWithright(k1);
}


AVLTree Insert(int x, AVLTree head)
{
    if (head == NULL)
    {
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
        head->left = Insert(x, head->left);
        // 判断平衡是否被破坏以及怎么样被破坏，如果被破坏，调整平衡
        if ((Height(head->left) - Height(head->right)) > 1)
        {
            if (x < head->left->value)
            {
                head = rotateWithleft(head);
            }
            else
            {
                head = doubleRotateWithleft(head);
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
                head = rotateWithright(head);
            }
            else
            {
                head = doubleRotateWithright(head);
            }
        }
    }
    return head;
}

int Height(Position p)
{
    if (p == NULL)
    {
        return -1;
    }
    else
    {
        return p->height;
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

void AVLTreeBFS(const AVLTree tree)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	Init(q);
	Enqueue(tree, q);
	while (!IsEmpty(q))
	{
		Position tmp = Dequeue(q);
		printf("%d ", tmp->value);
		if (tmp->left != NULL)
		{
			Enqueue(tmp->left, q);
		}
		if (tmp->right != NULL)
		{
			Enqueue(tmp->right, q);
		}
	}
}