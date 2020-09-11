#include<stdio.h>
#include <process.h>

#define MAX_ARRAY_SIZE 100

// 最简单暴力的方法，三重循环
int max_subsequence1(int list[], int n)
{

    int start;
    int end;
    int maxsum;
    for (start = 0; start < n; start++)
    {
        for (end = start; end < n; end++)
	{
            int cursum = 0;
	    for (int k = start; k < end; k++)
	    {
	        cursum += list[k];
	    }
	    if (cursum > maxsum) {
	        maxsum = cursum;
	    }
	}
    }
    return maxsum;
}


// 第二种改进的方法，只使用二重循环，去掉了最后一重循环，方法是子序列每增加一个长度就比较它和最大序列和的大小
int max_subsequence2(int list[], int n)
{
    int start;
    int end;
    int maxsum;
    for (start = 0; start < n; start++)
    {
        int cursum = 0;
        for (end = start; end < n; end++)
        {
            cursum += list[end];
            if (cursum > maxsum)
            {
                maxsum = cursum;
            }
        } 
    }
    return maxsum;
}

// 分治算法，将整个数组分为两个部分，最大子序列只可能出现在三个位置，要么是左边的部分，要么是右边的部分，要么是中间横跨的部分
int max_subsequence3(int list[], int first, int last) 
{
    int max_left = 0;
    int max_right = 0;
    int max_mid = 0;
    int mid = (first + last) / 2;
    // 这是一个错误检验，按理说按照正常分法最后应该是在first == last处结束
    if (first > last) 
    {
        return (0);
    }
    if (first == last) 
    {
        return list[first];
    }
    max_left = max_subsequence3(list, first, mid);
    max_right = max_subsequence3(list, mid + 1, last);
    max_mid =find_overlap(list, first, mid, last);
    if (max_left > max_right) 
    {
        if (max_left > max_mid)
        {
	        return max_left;
        } 
        else 
        {
	        return max_mid;
	    }
    } 
    else 
    {
        if (max_right < max_mid) 
        {
	        return max_mid;
        }
        else 
        {
	        return max_right;
        }
    }
}

// 分治算法辅助函数，寻找横跨数组中间形式的最大值
int find_overlap(int list[], int first, int mid, int last)
{
    int max_left = 0;
    int max_right = 0;
    int i;
    int sum;
    // 找从中间开始延伸到左边的最大和
    for (i = mid, sum = 0; i >= first; i--) 
    {
        sum += list[i];
        if (sum > max_left) 
        {
	        max_left = sum;
	    }
    }
    // 找从中间开始延伸到右边的最大和
    for (i = mid + 1, sum = 0; i <= last; i++) 
    {
        sum += list[i];
        if (sum > max_right) 
        {
	        max_right = sum;
	    }
    }
    return max_left + max_right;
}

// 使用一重循环的在线算法，这里的思想是前半部分与中间部分相接的序列如果为负值，那么前面的元素对在中间部分寻找最大子序列和没有影响
// 如果数组的第一个值为负，那么我们可以直接不考虑第一个元素，逻辑上缩小数组的规模
// 如果我们记录前半部分的最大和，如果在寻找中间部分的时候前半部分的最大和是负的，说明在前半部分（从数组中第一个元素开始的部分）中寻找的最大和子序列不能延伸到当前位置，那么我们从当前位置开始往后再寻找一个新的子序列
int max_subsequence(int list[], int n) {
    int maxsum = 0;
    int cursum = 0;
    int i;
    for (i = 0; i < n; i++) {
        cursum += list[i];
	    // 这里在逐步舍弃不符合条件的子序列中的数，可以看作是不断减小序列的规模
        if (cursum < 0) 
        {
	        cursum = 0;
	    }
        // 更新整体最大和
	    if (cursum > maxsum) 
        {
	        maxsum = cursum;
	    }
    }
    return maxsum;
}

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
            result = max_subsequence1(testArray, number);
            break;
        case 2:
            result = max_subsequence3(testArray, 0, number - 1);
            break;
        case 3:
            result = max_subsequence(testArray, number);
            break;
        default:
            result = 0;
            break;
    }
    printf("Result is:%d\n", result);
    system("pause");
    return 0;
}