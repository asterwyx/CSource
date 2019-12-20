#include <stdio.h>
#include <process.h>
#include "circuCursorList.h"

int main(int argc, char* argv[])
{
	int circleSize, gap;
	printf("Please enter size:");
	scanf("%d", &circleSize);
	printf("Please enter gap:");
	scanf("%d", &gap);
	InitializeCursorSpace();
	List JosephusCircle = CreateEmptyList();
	// 淘汰者游标开始放在表头的位置
	Position deadCursor = JosephusCircle;
	// 初始化Josephus环，插入第一个人，将游标移至第一个人的位置
	Insert(JosephusCircle, deadCursor, 1);
	deadCursor = GetFirst(JosephusCircle);
	for (int i = 1; i < circleSize; i++)
	{
		Insert(JosephusCircle, GetLast(JosephusCircle), i + 1);
	}
	// 检验Josephus环初始状态
	printf("\nInitial:");
	TraversePrint(JosephusCircle);
	if (IsEmpty(JosephusCircle))
	{
		perror("Empty list");
		printf("Not clear！！！\n");
		return 0;
	}
	Position TmpCell = null;
	int count = 1;
	while (!HasOnlyOne(JosephusCircle))
	{
		for (int i = 0; i < gap - 1; i++)
		{
			deadCursor = Advance(deadCursor);
		}
		TmpCell = deadCursor;
		deadCursor = Advance(deadCursor);
		Delete(JosephusCircle, Retrieve(TmpCell));
		printf("Result after %d\t round:", count);
		TraversePrint(JosephusCircle);
		count++;
	}
	// 打印结果
	printf("\nThe final winner is:%d\n", Retrieve(GetFirst(JosephusCircle)));
	// 删除链表
	DeleteList(JosephusCircle);
	system("pause");
	return 0;
}