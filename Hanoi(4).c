#include<stdio.h>

void hanoi(char s, char t1, char t2, char t, int n)
{
    if (0 == n)
    {
        return ;
    }
    
    if (1 == n)
    {
        printf("%c->%c", s, t);
    }
    hanoi(s, t1, t, t2, n-2);
    printf("%c->%c", s, t1);
    printf("%c->%c", s, t);
    printf("%c->%c", t1, t);
    hanoi(t2, t1, s, t, n-2);
    return ;
}