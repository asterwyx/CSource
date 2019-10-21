#ifndef _cursorList_H
#define _cursorList_H
#define MAX_SPACE 50

typedef int PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

void InitializaCursorSpace(void);

List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const List L, const Position P);
Position Find(int X, const List L);
void Delete(int X, List L);
Position FindPrevious(int X, const List L);
void Insert(List L, int X, Position P);
void DeleteList(List L);
Position Header(const List L);
Position First(const List L);
Position Advance(const Position P);
int Retrieve(const Position P);


#endif

typedef struct node
{
    int element;
    Position next; 
} Node;

Node cursorSpace[MAX_SPACE];
