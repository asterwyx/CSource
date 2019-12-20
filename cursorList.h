#ifndef cursorList__h
#define cursorList__h
#define MAX_SPACE 1024
#define YES 1
#define NO 0
#define ERROR -1
#define null ERROR

typedef int PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

typedef struct node
{
    int element;
    Position next; 
} Node;

extern void InitializaCursorSpace(void);
extern List CreateEmptyList(void);
extern int IsEmpty(const List L);
extern Position GetFirst(const List L);
extern int GetLast(const List L);
extern int HasOnlyOne(List L);
extern List MakeEmpty(List L);


extern Position Find(const List L, int element);
extern void Delete(List L, int element);
extern Position FindPrevious(const List L, int element);
extern void Insert(List L, Position P, int element);
extern void DeleteList(List L);
extern Position Header(const List L);

extern Position Advance(const Position P);
extern int Retrieve(const Position P);


#endif  /* _cursorList_H */
