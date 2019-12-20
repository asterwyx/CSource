#include <stdio.h>

char text[] = "abcbabcaadabcabc" ;
char pattern[] = "abcabc";
int s[20];

void get_SArray (char *p, int m)
{
    int i, j;
    s[0] = -1;
    for (i = 0, j = -1; i < m; )
    {
        if (j == -1 || p[i] == p[j])
        {
            j++; i++; 
            s[i] = j;
        }
        else 
            j = s[j];
    }
}

int KMP (char *p, int m, char *t, int n)
{
    int i, j;
    for (i = 0, j = 0; i < m && j < n;)
    {
        if (i == -1 || p[i] == t[j]) 
        {
            j++; i++;
        }
        else 
            i = s[i];
        if (i == m)
            return (j - i);
    }
    return (-1);
}

int main ()
{
    int n;
    
    get_SArray (pattern, 6);
    
    for (n = 0; n < 6; n++)
        printf ("s[%d] = %d ", n, s[n]);
    
    printf ("\n"); 
     
    printf ("result is %d\n", KMP(pattern, 6, text, 16));

    system("pause");
    
    return (0);
}
