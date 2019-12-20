#include<stdio.h>

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

// 分治算法
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
    for (i = mid, sum = 0; i >= first; i--) 
    {
        sum += list[i];
        if (sum > max_left) 
        {
	        max_left = sum;
	    }
    }
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

// 使用一重循环的在线算法
int max_subsequence(int list[], int n) {
    int maxsum = 0;
    int cursum = 0;
    int i;
    for (i = 0; i < n; i++) {
        cursum += list[i];
	// 这里在逐步舍弃不符合条件的子序列中的数，可以看作是不断减小序列的规模
        if (cursum < 0) {
	    cursum = 0;
	}
	if (cursum > maxsum) {
	    maxsum = cursum;
	}
    }
    return maxsum;
}

// 测试主函数
int main()
{
    int testArray[] = {-2, -6, 4, -1, 12, 2, -5, 5, 7, -13, -10, -3, -8, 8};
    int result = max_subsequence3(testArray, 0, 13);
    printf("Result is:%d\n", result);
    system("pause");
    return 0;
}