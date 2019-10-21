#include<stdio.h>

int water (int a[], int n) 
{ 
     int m = 0, tmp;
     int i = 0, j = n - 1;
    
     while (i < j)
     {
         if (a[i] < a[j])
              tmp = a[i]*(j - i++);
          else
              tmp = a[j]*(j-- - i);
          if (tmp > m)
               m = tmp;
     }

    return (m);
}

int main()
{
    int test[10] = {56, 87, 21, 45, 65, 78, 19, 75, 35, 25};
    int test2[10] = {56, 87, 21, 45, 65, 78, 19, 75, 35, 51};  // 等价类测试（我称之为递归测试）
    int result = water(test, 10);
    printf("%d\n", result);
    result = water(test2, 10);
    printf("%d\n", result);
    return 0;
}