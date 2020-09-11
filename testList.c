#include "testList.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Element;
    Position Next;
};


// 测试一个表是否是空表
int IsEmpty(List L)
{
    return L->Next == NULL;
}


int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

Position Find(int X, List L)
{
    Position P;

    P = L->Next;
    while (P != NULL && P->Element != X)
    {
        P = P->Next;
    }
    return P;
}

void Delete(int X, List L)
{
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if (!IsLast(P, L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

Position FindPrevious(int X, List L)
{
    Position P;
    
    P = L;
    while (P->Next != NULL && P->Next->Element != X)
    {
        P = P->Next;
    }
    
    return P;
}

void Insert(int X, List L, Position P)
{
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
        printf("Out of space!!!");
    }
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList(List L)
{
    Position P, TmpPosi;

    P = L->Next;
    L->Next = NULL;
    while (P != NULL)
    {   
        TmpPosi = P->Next;
        free(P);
        P = TmpPosi;
    }
}

Position Header(List L)  // 返回链表头，即一个哑结点
{
    return L;
}

Position First(List L)  // 返回链表的第一个结点
{
    return L->Next;
}

Position Advance(Position P)  // 返回后继元的位置
{
    return P->Next;
}

int Retrieve(Position P)  // 取某一个位置的元素
{
    return P->Element;
}