#include"BST.h"
int FindBSTMax(SearchTree T)
{
    SearchTree tmpTree = T;
    
    
    while (tmpTree->rightChild != NULL)
    {
        tmpTree = tmpTree->rightChild;
    }
    return tmpTree->value;
}

SearchTree insert (int x, SearchTree T)
{
    if (T != NULL)
    {
        if (x < T->value)
        {
	    T->leftChild = insert(x, T->leftChild);
        }
        else
	{
	    T->rightChild = insert(x, T->rightChild);
        }
    }
    else
    {
        T = (SearchTree)malloc(sizeof(TreeNode));    
	T->leftChild = NULL;
	T->rightChild = NULL;
	T->value = x;
    }
    return T;
} 
