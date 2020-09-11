#include <stdio.h>
#include <string.h>
#define YES 1
#define NO  0
#define MAX_ELE 1001       // 并查集中的元素值不能超过1000
// 为了能使值直接映射到地址，这里使用数组实现
// 如果要使用链表实现，必须实现值到地址的映射，这时候因为父亲结点是不知道儿子结点的，没办法只存储父亲结点然后从父亲结点开始对比值返回地址
// 只能再开辟一个顺序结构存储值和地址的映射，然后顺序查找，这要花费O(N)的时间复杂度，或者使用关键值对应查找，这要经过精心设计
// 或者不实现值到地址的映射，直接只操作地址
typedef int element_t;
typedef struct node
{
    element_t value;
    int parent;
    int rank;
} Node;

// 全局内存集合，并查集存储在这个数组中
Node sets_space[MAX_ELE];
int find_root(int x);
void union_set(int x, int y);
int has_relationship(int x, int y);

int main()
{
    // memset(sets_space, 0, MAX_ELE * sizeof(Node)); // 数组初始化
    int r1, r2;
    int n;
    int m;
    printf("How much element(< 1000)?\n");
    scanf("%d", &n);
    printf("How much relationship?\n");
    scanf("%d", &m);
    // 初始化
    for (int i = 0; i <= n; i++)
    {
        sets_space[i].parent = i;
        sets_space[i].rank = 0;
        sets_space[i].value = i;
    }
    // 关系合并
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &r1, &r2);
        union_set(r1, r2);
    }
    printf("Please query:\n");
    while (1)
    {
        scanf("%d%d", &r1, &r2);
        if (r1 < 0 || r2 < 0)
        {
            break;
        }
        int result = has_relationship(r1, r2);
        if (result == YES)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }  
    }
    return 0;
}

int find_root(int x)
{
    if (sets_space[x].parent != x)
    {
        // 递归的路径压缩，直到根结点结束
        sets_space[x].parent = find_root(sets_space[x].parent);
    }
    return sets_space[x].parent;
}

void union_set(int x, int y)
{
    if (has_relationship(x, y) == YES)
    {
        return;
    }
    else
    {
        int r1 = find_root(x);
        int r2 = find_root(y);
        // 按秩合并
        if (sets_space[r1].rank > sets_space[r2].rank)
        {
            sets_space[r2].parent = r1;
        }
        else if (sets_space[r1].rank < sets_space[r2].rank)
        {
            sets_space[r1].parent = r2;
        }
        else
        {
            sets_space[r2].parent = r1;
            sets_space[r1].rank++;
        }
    }
    
}

int has_relationship(int x, int y)
{
    if (find_root(x) == find_root(y))
    {
        return YES;
    }
    else
    {
        return NO;
    }
}

