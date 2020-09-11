#include <stdio.h>
#include "cursorList.h"

int main()
{
    InitializaCursorSpace();
    List test = CreateEmptyList();
    for (int i = 1; i < 10; i++)
    {
        Insert(test, test, i);
    }
    Position e = GetFirst(test);
    for (int i = 0; i < 9; i++)
    {
        printf("%d", e);
        e = Advance(e);
    }
    return 0;
}
