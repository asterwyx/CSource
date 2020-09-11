#include <stdio.h>

#define M    (16)

static int pos[M];
static int cnt = 0;

static void print_board (int n)
{
    int i, j;
            
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            if ((1 << i) & pos[j])
                printf ("  1");
            else
                printf ("  0");
        }
        printf ("\n");
    }
    printf ("\n");
    
    return;
}

static void search (int n, int row, int co, int tl, int tr)
{
    int bits, p;
    
    if (co == (1 << n) - 1) // all columns have been filled
    {
        cnt++;    //new success
        print_board (n);
        return;
    }
        
    bits = (~(co | tl | tr)) & ((1 << n) - 1);  //all of the available cells are set to 1
    while (bits)
    {
        p = bits & -bits;  //try the leftmost cell
        pos[row] = p;    //update the record
        bits &= (bits - 1);  //mark p as tested
        search (n, row + 1, co | p, (tl | p) << 1, (tr | p) >> 1);    //move downward to the next row
    }

    return;
}


int main (void)
{
    int n = 20;
    
    search (n, 0, 0, 0, 0);
    
    printf ("total number of solutions: %d\n", cnt);
    system("pause");
    
    return 0; 
}