#include <stdio.h>
#include "circuCursorList.h"


Node cursorSpace[MAX_SPACE];

// 初始化链表空间
void InitializeCursorSpace(void)
{
    for (int i = 0; i < MAX_SPACE - 1; i++)
    {
        // 初始化全局结构体
        cursorSpace[i].element = 0;
        cursorSpace[i].next = i + 1;
    }

    cursorSpace[MAX_SPACE - 1].element = 0;
    // 用指向-1来代表指向空
    cursorSpace[MAX_SPACE - 1].next = null; 
    
}

// 分配链表节点
static Position CursorAlloc(void)
{
    Position P;
    // 数组的第一个元素始终作为空闲链表的表头，将空闲链表的第一个节点返回
    P = cursorSpace[0].next;
    cursorSpace[0].next = cursorSpace[P].next;

    return P;
}

// 回收链表节点
static void CursorFree(Position P)
{
    // 将要释放的节点放在空闲链表的表头
    cursorSpace[P].next = cursorSpace[0].next;
    cursorSpace[0].next = P;
}

// 创建一个空的链表
List CreateEmptyList(void)
{
    List L;
    L = CursorAlloc();
    if (L == null)
    {
		perror("Out of space!!!");
    }
    cursorSpace[L].next = null;
	return L;
}

// 判断是否是空表
int IsEmpty(const List L)
{
    if (cursorSpace[L].next == null)
    {
        return YES;
    }
    else
    {
        return NO;
    }
}

// 返回链表的第一个元素的位置
Position GetFirst(const List L)
{   
    if (IsEmpty(L))
    {
        perror("Empty list!!!");
    }
    return cursorSpace[L].next;
}

// 判断该循环链表是否只有一个节点
int HasOnlyOne(const List L)
{
    if (IsEmpty(L))
    {
        return ERROR;
    }
    Position First = GetFirst(L);
    if (cursorSpace[First].next == First)
    {
        return YES;
    }
    else
    {
        return NO;
    }
}

// 将链表置空
List MakeEmpty(List L)
{
    Position TmpCell, First;
    while (!HasOnlyOne(L))
    {
        First = GetFirst(L);
        TmpCell = cursorSpace[First].next;
        cursorSpace[First].next = cursorSpace[TmpCell].next;
        CursorFree(TmpCell);
    }
    CursorFree(cursorSpace[L].next);
    cursorSpace[L].next = null;
	return L;
}

// 返回一个被查找元素在表中第一次出现的位置
Position Find(const List L, int element)
{
    if (IsEmpty(L))
    {
        perror("Empty list!!!");
    }
    Position P;
    P = GetFirst(L);
    while (cursorSpace[P].next != GetFirst(L))
    {
        if (cursorSpace[P].element == element)
        {
            return P;
        }
        P = cursorSpace[P].next;
    }
    if (cursorSpace[P].element == element)
    {
        return P;
    }
    else
    {
        return null;
    }
}

// 对链表进行删除操作
void Delete(List L, int element)
{   
    if (IsEmpty(L))
    {
        perror("Empty list!!!");
    }
    Position P, TmpCell;

    if (HasOnlyOne(L))
    {
        if (cursorSpace[GetFirst(L)].element == element)
        {
            CursorFree(GetFirst(L));
            cursorSpace[L].next = null;
        }
    }
    
    // 在链表中寻找元素第一次出现的位置，因为是要进行删除操作，所以得到父节点更好
    P = FindPrevious(L, element);
	if (P != null)
	{
		TmpCell = cursorSpace[P].next;
		cursorSpace[P].next = cursorSpace[TmpCell].next;
		CursorFree(TmpCell);
		if (TmpCell == GetFirst(L))
		{
			cursorSpace[L].next = cursorSpace[P].next;
		}
	}
}

// 寻找指定数据的上一个节点
Position FindPrevious(const List L, int element)
{
    if (IsEmpty(L))
    {
        perror("Empty list!!!");
    }
    Position P;
    P = cursorSpace[GetFirst(L)].next;
    while (P != GetFirst(L))
    {
        if (cursorSpace[cursorSpace[P].next].element == element)
        {
            return P;
        }
        P = cursorSpace[P].next;
    }
    if (cursorSpace[cursorSpace[P].next].element == element)
    {
        return P;
    }
    return null;
}

// 对链表进行插入操作
void Insert(List L, Position P, int element)
{
    Position TmpCell;

    TmpCell = CursorAlloc();

    if (TmpCell == null)
    {
        perror("Out of space!!!");
		return ;
    }
    
	cursorSpace[TmpCell].element = element;
    
	if (IsEmpty(L))
    {
        if (P == L)
        {
            cursorSpace[L].next = TmpCell;
            cursorSpace[TmpCell].next = TmpCell;
            return ;
        }
        else
        {
            CursorFree(P);
            perror("No such position");
			
			return ;
        }
    }
    else
    {
        if (P == L)
        {
            Position Last = FindPrevious(L, cursorSpace[GetFirst(L)].element);
            cursorSpace[TmpCell].next = GetFirst(L);
            cursorSpace[Last].next = TmpCell;
            cursorSpace[L].next = TmpCell;
        }
        else
        {
            if (FindPrevious(L, P))
            {
                cursorSpace[TmpCell].next = cursorSpace[P].next;
                cursorSpace[P].next = TmpCell;
            }
            else
            {
                perror("No such position");
            }
        }
    }
}

// 删除一个链表
void DeleteList(List L)
{
	MakeEmpty(L);
	CursorFree(L);
}

// 返回一个节点的下一个节点
Position Advance(const Position P)
{
    return cursorSpace[P].next;
}

// 取得P位置处的元素
int Retrieve(const Position P)
{
    return cursorSpace[P].element;
}