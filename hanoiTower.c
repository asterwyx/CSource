#include <stdio.h>

void hanoiTower(int n, char source, char temp, char target)
{
    if (n < 1)
        return ;
    if (1 == n)
    {
        printf("%c -> %c\n", source, target);
        return ;
    }
    hanoiTower(n-1, source, target, temp);
    printf("%c -> %c\n", source, target);
    hanoiTower(n-1, temp, source, target);
    return ;
}
int main()
{
    hanoiTower(4, 'A', 'B', 'C');
}
