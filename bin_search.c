#include <stdio.h>
int bin_search(int a[], int x, int first, int last)
{
    int mid = (first + last) / 2;

    if (first > last) {
        return -1;
    }
    if (x < a[mid])
    {
        return bin_search(a, x, first, mid - 1);
    }
    else if (x > a[mid])
    {
        return bin_search(a, x, mid + 1, last);
    }
    else
    {
        return mid;
    }
}

int main(int argc, char const *argv[]) {
    int array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int result = bin_search(array, 8, 0, 9);
    printf("%d\n", result);
    return 0;
}
