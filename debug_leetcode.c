#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

// 中心扩展算法
char *center_extend(char *str, int len);

char *longestPalindrome(char *s)
{
    int len = strlen(s);
    if (0 == len || s == NULL)
    {
        return s;
    }
    char *result = center_extend(s, len);
    return result;
}

char *center_extend(char *str, int len)
{
    int ext_len = 2 * len + 1;
    char *ext = (char *)malloc(ext_len + 1);
    int *p = (int *)malloc(ext_len * sizeof(int));
    // 预处理，形成扩展后的数组（总是奇数个字符）
    ext[0] = '#';
    for (int i = 0; i < len; i++)
    {
        ext[2 * i + 1] = str[i];
        ext[2 * i + 2] = '#';
    }
    ext[ext_len] = 0;
    int radius, start, end;
    for (int i = 0; i < ext_len; i++)
    {
        radius = 0;
        start = i - 1;
        end = i + 1;
        while (start != -1 && end != ext_len)
        {
            if (ext[start] == ext[end])
            {
                radius++;
                --start;
                ++end;
            }
            else
            {
                break;
            }
        }
        p[i] = radius;
    }
    int max_idx = 0;
    int max_p = 0;
    for (int i = 0; i < ext_len; i++)
    {
        if (p[i] > max_p)
        {
            max_idx = i;
            max_p = p[i];
        }
    }
    char *result = (char *)malloc(max_p + 1);
    strncpy(result, str + (max_idx - p[max_idx]) / 2, max_p);
    free(ext);
    free(p);
    result[max_p] = 0;
    return result;
}

int main() {
    char str[] = "babad";
    char *s = longestPalindrome(str);
    printf("%s\n", s);
    free(s);
    system("pause");
    return 0;
}
