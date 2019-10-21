#include<stdio.h>

int max_subsequen(int list[], int n)
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