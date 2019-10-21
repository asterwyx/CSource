#include <stdio.h>
#include <stdlib.h>

#define overflow -1
#define ok 1
#define error 0

typedef int status;
typedef char elemtype;
typedef struct lnode {
	elemtype data;
	struct lnode* next;
} lnode, * linklist;


status initlist(linklist *L)  // 记得传参要取指针的地址
{	
	// 初始化链表
	if (!*L)
	{
		*L = (lnode*)malloc(sizeof(lnode));
		(*L)->next = NULL;
		return ok;
	}
	else
	{
		return error;
	}
	
}

status listinsert(linklist L, int i, elemtype e)
{
	if (!L)
	{
		return error;
	}
	linklist plist = L;
	for (int j = 1; j < i; j++)
	{
		if (plist->next == NULL)
		{
			return overflow;
		}
		else
		{
			plist = plist->next;
		}
	}

	linklist addingItem = (lnode*)malloc(sizeof(lnode));
	if (plist->next == NULL)
	{
		addingItem->next = NULL;
	}
	else
	{
		addingItem->next = plist->next;
	}
	plist->next = addingItem;
	addingItem->data = e;
	return ok;
}

status listtraverse(linklist L)
{	
	if (!L)
	{
		return error;
	} // 如果链表没有初始化就返回错误
	linklist plist = L;
	while (plist->next != NULL)
	{
		printf("%c", plist->next->data);
		plist = plist->next;
	}
	return ok;
}

status getelem(linklist L, int i, elemtype *ptrToE)
{
	if (!L)
	{
		return error;
	}
	linklist plist = L;
	for (int j = 1; j < i; j++)
	{
		if (plist->next == NULL)
		{
			return overflow;
		}
		else
		{
			plist = plist->next;
		}
	}
	*ptrToE = plist->next->data;
	return ok;
}

int locateelem(linklist L, elemtype e)
{
	if (!L)
	{
		return error;
	}
	else
	{
		linklist plist = L;
		for (int location = 1; plist->next != NULL; location++)
		{
			if (plist->data == e)
			{
				return location;
			}
		}
		return overflow;
	}
}


status listdelete(linklist L, int i)
{
	if (!L)
	{
		return error;
	}
	linklist plist = L;
	for (int j = 1; j < i; j++)
	{
		if (plist->next == NULL)
		{
			return overflow;
		}
		else
		{
			plist = plist->next;
		}
	}
	if (plist->next == NULL)
	{
		return overflow;
	}
	linklist tmp = plist->next->next;
	free(plist->next);
	plist->next = tmp;
	return ok;
}


status destroylist(linklist *L)  // 注意这里是指针的指针，传参的时候要取指针的地址
{
	linklist plist = (*L)->next;
	linklist tmp;
	while (plist != NULL)
	{
		tmp = plist->next;
		free(plist);
		plist = tmp;
	}
	free(L);
	*L = NULL; // 删除后如果此指针不再指向其他有用内容，一定要记得置空
	return ok;
}


int main()
{
	elemtype e;
	linklist L = NULL;
	int testCase;
	printf("输入测试种类：");
	scanf("%d", &testCase);
	printf("(1)初始化线性链表L：\n");
	initlist(&L);
	printf("(2)依次在线性表L尾插入字符a,b,c,d,e：\n");
	listinsert(L, 1, 'a');
	listinsert(L, 2, 'b');
	listinsert(L, 3, 'c');
	listinsert(L, 4, 'd');
	listinsert(L, 5, 'e');
	printf("(3)在线性表L的第2个位置之前插入字符f：\n");
	listinsert(L, 2, 'f');
	switch (testCase)
	{
	case 1:  // 遍历
		printf("(4)输出线性表L：\n");
		listtraverse(L);
		break;
	case 2:  // 取元素
		printf("(5)输出线性表的第3个元素：\n");
		getelem(L, 3, &e);
		printf("%c", e);
		break;
	case 3:  // 定位元素
		printf("(6)输出元素d在线性表的L中的位置：\n");
		printf("%d", locateelem(L, 'd'));
		break;
	case 4:  // 删除元素
		printf("(7)删除线性表L的第4个元素：\n");
		listdelete(L, 4);
		printf("(8)输出线性表L：\n");  // 确定删除效果
		listtraverse(L);
		break;
	default:
		//遍历
		printf("(4)输出线性表L：\n");
		listtraverse(L);
		// 取元素
		printf("(5)输出线性表的第3个元素：\n");
		getelem(L, 3, &e);
		printf("%c", e);
		// 定位元素
		printf("(6)输出元素d在线性表的L中的位置：\n");
		printf("%d", locateelem(L, 'd'));
		// 删除元素
		printf("(7)删除线性表L的第4个元素：\n");
		listdelete(L, 4);
		printf("(8)输出线性表L：\n");  // 确定删除效果
		listtraverse(L);
		break;
	}

	printf("(9)释放线性表：\n");
	destroylist(&L);
	return 0;
}