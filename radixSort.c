#include <stdio.h>
#include "queue.h"
#define MAX_LENGTH 100
#define MAX_BUCKETS 16
void radixSort(int array[], int n, Queue* q[], int radix)
{
	int radixLevel = 1;
	while (1)
	{
		// 入桶
		for (int i = 0; i < n; i++)
		{
			int bucketnum = (array[i] / radixLevel) % radix;
			Enqueue(array[i], q[bucketnum]);
		}

		// 结束循环入口，最后总会有一次循环所有的数全部都进到了0号桶，这会使整个算法的时间加上n，但是考虑到如果要提前获取数组元素的最高位数也是需要遍历的，而且这个操作不影响时间复杂度的数量级
		if (q[0]->num == n)
		{
			for (int i = 0; i < n; i++)
			{
				array[i] = Dequeue(q[0]);
			}
			break;
		}


		// 出桶
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			while (q[j]->num == 0)
			{
				j++;
			}
			array[i] = Dequeue(q[j]);
		}
		radixLevel *= radix;
	}
}

int main(void)
{
	// 进行各种辅助工具的初始化
	int source[MAX_LENGTH] = {0};
	// 默认使用桶最大的数量作为排序基数	
	int radix = MAX_BUCKETS;
    int number = 0;
    printf("Please enter size, no greater than %d\n", MAX_LENGTH);
    scanf("%d", &number);

	printf("Please enter radix, no greater than %d:", MAX_BUCKETS);
	scanf("%d", &radix);


    printf("Please enter the sequence\n");
    for (int i = 0; i < number; ++i)
    {
        scanf("%d", source + i); // 输入序列
    }
	// 初始化桶
	Queue* buckets[MAX_BUCKETS];
	for (int i = 0; i < MAX_BUCKETS; i++)
	{
		buckets[i] = (Queue*)malloc(sizeof(Queue));
		if (buckets[i] != NULL)
		{
			Init(buckets[i]);
		}
		else
		{
			perror("Out of space!");
			exit(EXIT_FAILURE);
		}
	}

	// 开始排序，使用基数10排序
	radixSort(source, number, buckets, radix);

	for (int i = 0; i < number; i++)
	{
		printf("%d, ", source[i]);
	}
	printf("\n");
    system("pause");
	return 0;
}