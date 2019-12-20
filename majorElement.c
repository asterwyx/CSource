#include <stdio.h>
#include <process.h>

#define NO_MAJORELE -1
#define MAX_ARRAY_SIZE 100

// 两个为一组地减小数组的规模，用这种方式得到的子数组，如果有主元，那么子数组的主元也是原数组的主元。
//这样递归地执行，直到只有一个元素（有主元）或者零个元素（没有主元）
int majEle_recursive(int a[], int n) {
    int i, j, k = n /2;
    int tmp;
    if (0 == n) 
    {
        return NO_MAJORELE;
    }
    if (1 == n)
    {
        return a[0];
    }
    for (i = 0, j = 0; i < k; i++) 
    {
        if (a[2 * i] == a[2 * i + 1]) 
        {
	        tmp = a[j];
	        a[j++] = a[2 * i];
	        a[2 * i] = tmp;  
        }
    }
    tmp = majEle_recursive(a, j);
    if (n % 2 == 1) {
        if (tmp == NO_MAJORELE) 
        {
	        return a[n - 1];
        }
    }
    return tmp;
}

// 迭代形式的代码，线性时间复杂度的代码
int majEle_loop(int a[], int n) {
    int i, count = 0;
    int tmp = NO_MAJORELE;
    for (i = 0; i < n; i++)
    {
        if (a[i] == tmp)
        {
	        count++;  // tmp记录的是当前重复元素，这里计算重复次数
        }
        else if (count == 0)
        {
            tmp = a[i]; // 这里重置重复元素，因此count的最小值一定是0
            count++;
        }
        else
        {
            count--;
        }
    }
    if (count == 0)
    {
        return NO_MAJORELE;
    }
    else
    {
        count = 0; // 当前记录次数清零
        // 重新检验该元素是否真的是主元
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == tmp)
            {
                count++;
            }
        }
        if (count > n / 2)
        {
            return tmp;
        }
        else
        {
            return NO_MAJORELE;
        }
    }
}
// 这个线性时间算法的原理是计算元素出现的次数。
// 虽然之前计算的次数可能会因为在下一次碰到不是这个元素而减少，但是作为主元，这样计算的话出现次数最终必然是大于零的，如果最后次数等于零，说明这个数组没有主元。
// 测试主函数
int main()
{
    int testArray[MAX_ARRAY_SIZE] = {0};
    int number, kind; // 要求的序列的大小
    printf("Please enter size, no greater than %d\n", MAX_ARRAY_SIZE);
    scanf("%d", &number);
    printf("Please enter the sequence\n");
    for (int i = 0; i < number; ++i)
    {
        scanf("%d", testArray + i); // 输入序列
    }
    printf("Choose method\n");
    scanf("%d", &kind);
    int result = 0;
    switch (kind) {
        case 1:
            result = majEle_recursive(testArray, number);
            break;
        case 2:
            result = majEle_loop(testArray, number);
            break;
        default:
            result = 0;
            break;
    }
    printf("Result is:%d\n", result);
    system("pause");
    return 0;
}
