#include <stdio.h>
#include <process.h>

#define MAX_SIZE 100
void merge(int list[], int start1, int end1, int start2, int end2)
{
    // 左边指针ptr1，右边指针ptr2，缓存数组指针ptr
    int ptr1 = start1, ptr2 = start2, ptr = 0;
    // 设置缓存数组
    int cache[MAX_SIZE] = {0};
    // 设置缓存数组的长度
    int length = end1 - start1 + end2 - start2 + 2;

    while (1)
    {
        if (list[ptr1] < list[ptr2])
        {
            cache[ptr] = list[ptr1];
            ptr1++;
            if (ptr1 == end1 + 1)
            {
                // 第一个数组的所有元素已经被拷贝完
                // 将第二个数组中所有剩下的元素全部拷贝进缓存
                for (; ptr2 <= end2; ptr2++)
                {
                    ptr++;
                    cache[ptr] = list[ptr2];
                }
                //退出循环，拷贝完成
                break;
            }
        }
        else
        {
            cache[ptr] = list[ptr2];
            ptr2++;
            if (ptr2 == end2 + 1)
            {
                for (; ptr1 <= end1; ptr1++)
                {
                    ptr++;
                    cache[ptr] = list[ptr1];
                }
                break;
            }
        }
        ptr++;
    }
    // 拷贝回原来的数组
    for (int i = 0; i < length; i++)
    {
        list[i + start1] = cache[i];
    }
    
}

void mergeSort(int list[], int start, int end)
{
    if (start == end)
    {
        return ;
    }
    int mid = (start + end) / 2;
    // 分的过程
    mergeSort(list, start, mid);
    mergeSort(list, mid + 1, end);
    // 合的过程，在合的过程完成了治
    merge(list, start, mid, mid + 1, end);
}

int main()
{
    int source[MAX_SIZE] = {0};
    int number = 0;
    printf("Please enter size, no greater than %d\n", MAX_SIZE);
    scanf("%d", &number);
    printf("Please enter the sequence\n");
    for (int i = 0; i < number; ++i)
    {
        scanf("%d", source + i); // 输入序列
    }

    // 开始排序
    mergeSort(source, 0, number - 1);

    printf("Result is:\n");
    for (int i = 0; i < number; i++)
    {
        printf("%d, ", source[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}