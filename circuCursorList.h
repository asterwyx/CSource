#ifndef circuCursorList__h
#define circuCursorList__h
#define MAX_SPACE 1024
#define YES 1
#define NO 0
#define ERROR -1
#define null ERROR

typedef int PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

// 链表节点声明
typedef struct node
{
    int element;
    Position next; 
} Node;

// 初始化链表分配空间
extern void InitializeCursorSpace(void);
// 创建空表
extern List CreateEmptyList(void);
// 判断是否是空表
extern int IsEmpty(const List L);
// 返回链表的第一个元素的位置
extern Position GetFirst(const List L);
// 返回循环链表中最后一个节点的位置
extern Position GetLast(const List L);
// 判断该循环链表是否只有一个节点
extern int HasOnlyOne(const List L);
// 将链表置空
extern List MakeEmpty(List L);
// 返回一个被查找元素在表中第一次出现的位置
extern Position Find(const List L, int element);
// 对链表进行删除操作
extern void Delete(List L, int element);
// 寻找指定数据的上一个节点
extern Position FindPrevious(const List L, int element);
// 对链表进行插入操作
extern void Insert(List L, Position P, int element);
// 删除一个链表
extern void DeleteList(List L);
// 返回一个节点的下一个节点
extern Position Advance(const Position P);
// 取得P位置处的元素
extern int Retrieve(const Position P);
// 遍历打印循环链表
extern void TraversePrint(const List L);


#endif  /* circuCursorList__h */
