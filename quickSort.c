#include<stdio.h>
#define swap(a, x, y) { int tmp = a[x]; a[x] = a[y]; a[y] = tmp; }

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
	pivot = comp_median3(list, start, end);
	if (end - start <= 2)
	{
		return ;
	}
    int low = start;
    int high = end - 1;


    while (1)
    {
        while (list[++low] < pivot);

        while (list[--high] > pivot);
        
        if (low < high)
        {
            swap(list, low, high);
        }
        else
        {
            break;
        }
    }
    
    swap(list, low, end - 1);
    
    // 分治
    quickSort(list, start, low-1);
    quickSort(list, high+1, end);
}



int main()
{
    int testArray[10] = {45, 7, 97, 34, 554, 345, 32, 34, 65, 78};
    quickSort(testArray, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", testArray[i]);
    }
    system("pause");
    return 0;
}