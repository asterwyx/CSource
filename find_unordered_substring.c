#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INFINITY    100000

int check_non_null(int *num, int len) {
    for (int i = 0; i < len; i++)
    {
        if (num[i] == -1) {
            return 0;
        }
    }
    return 1;
}

int find_min(int *num, int len) {
    int min = INFINITY;
    for (int i = 0; i < len; i++)
    {
        if (num[i] < min)
        {
            min = num[i];
        }
        
    }
    return min;
}

char *find_unordered(char *source, int s_len, char *short_sequence_t, int t_len) {
    int *l_pos = (int *)malloc(sizeof(int) * t_len);
    memset(l_pos, 0xff, t_len * sizeof(int) * t_len);
    int flag = 0;
    int start = -1;
    int final_start = -1;
    int min_len = INFINITY;
    for (int i = 0; i < s_len; ++i) {
        for (int j = 0; j < t_len; ++j) {
            if (source[i] == short_sequence_t[j]) {
                l_pos[j] = i;
            }
        }
        if (!flag) {
            flag = check_non_null(l_pos, t_len);
        }

        if (flag) {
            start = find_min(l_pos, t_len);
            if ((i - start + 1) < min_len) {
                min_len = i - start + 1;
            }
            final_start = start;
        }
    }
    char *result = (char *)malloc(min_len + 1);
    strncpy(result, source + final_start, min_len);
    result[min_len] = 0;
    return result;
}



int main() {
    char source[] = "ABDOBHEDACIHEBDAC";
    char short_s[] = "ABC";
    char *result = find_unordered(source, strlen(source), short_s, strlen(short_s));
    printf("%s\n", result);
    free(result);
    system("pause");
    return 0;
}