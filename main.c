#include "testList.c"
int main(void)
{
    List l1 = malloc(sizeof(struct Node));
    if (IsEmpty(l1))
    {
        printf("这个表是空的。\n");
    }
    return 0;
}