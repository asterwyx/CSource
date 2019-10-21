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
    while (T != NULL)
    {
        if (x < T)
        {
            /* code */
        }
        
    }
    
    
} 