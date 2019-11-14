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

// ����ڵ�����
typedef struct node
{
    int element;
    Position next; 
} Node;

// ��ʼ���������ռ�
extern void InitializeCursorSpace(void);
// �����ձ�
extern List CreateEmptyList(void);
// �ж��Ƿ��ǿձ�
extern int IsEmpty(const List L);
// ��������ĵ�һ��Ԫ�ص�λ��
extern Position GetFirst(const List L);
// �жϸ�ѭ�������Ƿ�ֻ��һ���ڵ�
extern int HasOnlyOne(const List L);
// �������ÿ�
extern List MakeEmpty(List L);
// ����һ��������Ԫ���ڱ��е�һ�γ��ֵ�λ��
extern Position Find(const List L, int element);
// ���������ɾ������
extern void Delete(List L, int element);
// Ѱ��ָ�����ݵ���һ���ڵ�
extern Position FindPrevious(const List L, int element);
// ��������в������
extern void Insert(List L, Position P, int element);
// ɾ��һ������
extern void DeleteList(List L);
// ����һ���ڵ����һ���ڵ�
extern Position Advance(const Position P);
// ȡ��Pλ�ô���Ԫ��
extern int Retrieve(const Position P);


#endif  /* circuCursorList__h */
