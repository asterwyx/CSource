#include<stdio.h>
#include <process.h>

#define swap(a, x, y) { int tmp = a[x]; a[x] = a[y]; a[y] = tmp; }
#define MAX_SIZE 100

int comp_median3(int a[], int left, int right)
{
	int ctr = (left + right) / 2;
	// 选择第一个数，最后一个数和中间的一个数中的中位值，并将他们按照从小到大的顺序交换
	if (a[ctr] < a[left])
		swap(a, left, ctr);
	if (a[right] < a[left])
		swap(a, right, left);
	if (a[right] < a[ctr])
		swap(a, ctr, right);
	// 交换枢纽元和倒数第二个元素
	swap(a, ctr, right - 1);
	return (a[right - 1]);
}

// 选择第一个元素作为枢纽元
void quick_sort(int list[], int start, int end)
{
    if (start >= end)
    {
        return ;
    }

    int low = start;
    int high = end;


    while (low < high)
    {
        while (list[high] >= list[start] && high > low)
        {
            high--;
        }
        while (list[low] <= list[start] && high > low)
        {
            low++;
        }
        swap(list, low, high);
    }

    swap(list, low, start);
    
    
    // 分治
    quick_sort(list, start, low-1);
    quick_sort(list, high+1, end);
}

// 使用三者取中的方法选择枢纽元
void quickSort(int list[], int start, int end)
{
	int pivot;
    if (start >= end)
    {
        return ;
    }
    // 选择枢纽元，枢纽元位于end - 1的位置
	pivot = comp_median3(list, start, end);
    // 特殊检验，只有三个元素的数组在枢纽元选择过程中已经排好了
	if (end - start <= 2)
	{
		return ;
	}

    // 初始化左右指针
    int low = start;
    int high = end - 1;

    while (1)
    {
        // 左右指针开始移动，先移动左指针
        while (list[++low] < pivot);

        while (list[--high] > pivot);
        
        // 停止之后检测是否结束
        if (low < high)
        {
            // 如果没有结束交换两个元素
            swap(list, low, high);
        }
        else
        {
            // 结束了退出循环
            break;
        }
    }
    
    // 将枢纽元放回正确的位置
    swap(list, low, end - 1);
    
    // 分治
    quickSort(list, start, low-1);
    quickSort(list, high+1, end);
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
    quickSort(source, 0, number - 1);

    printf("Result is:\n");
    for (int i = 0; i < number; i++)
    {
        printf("%d, ", source[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}