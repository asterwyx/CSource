#include <stdio.h>
#define NO_MAJORELE -1

int majEle_recursive(int a[], int n) {
    int i, j, k = n /2;
    int tmp;
    if (0 == n) {
        return NO_MAJORELE;
    }
    if (1 == n) {
        return a[0];
    }
    for (i = 0, j = 0; i < k; i++) {
        if (a[2 * i] == a[2 * i + 1]) {
	    tmp = a[j];
	    a[j++] = a[2 * i];
	    a[2 * i] = tmp;  // 为什么需要在这里进行交换而不直接赋值呢?如果是为了不改变原数组，不丢失原数组的信息倒是可以理解
        }
    }
    tmp = majEle_recursive(a, j);
    if (n % 2 == 1) {
        if (tmp == NO_MAJORELE) {
	    return a[n - 1];
        }
    }
    return tmp;
}

// 迭代形式的代码，线性时间复杂度的代码
int majEle_loop(int a[], int n) {
    int i, count = 0;
    int tmp = NO_MAJORELE;
    for (i = 0; i < n; i++) {
        if (a[i] == tmp) {
	    count++;  // tmp记录的是当前重复元素，这里计算重复次数
        }
	else if (count == 0) {
	    tmp = a[i]; // 这里重置重复元素，因此count的最小值一定是0
	    count++;
	}
	else {
	    count--;
	}
    }
    if (count == 0) {
        return NO_MAJORELE;
    }
    return tmp;
}
// 这个线性时间算法的原理是计算元素出现的次数，虽然之前计算的次数可能会因为在下一次碰到不是这个元素而减少，但是作为主元，这样计算的话出现次数最终必然是大于零的，如果最后次数等于零，说明这个数组没有主元。

// 测试主函数
int main() {
    int testArray[13] = {4, 5, 5, 5, 3, 5, 6, 5, 7, 5, 7, 5, 5};
    int result = majEle_loop(testArray, 13);
    printf("Result is:%d\n", result);
    system("pause");
    return 0;
}
