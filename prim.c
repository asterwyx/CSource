#include<stdio.h>
#include <process.h>

#define MAX 100 
#define MAXCOST 0x7fffffff 

int graph[MAX][MAX];

void prim(int graph[][MAX], int n)
{
    int lowcost[MAX];
    int mst[MAX];
    int i, j, min, minid, sum = 0;
    for (i = 2; i <= n; i++)
    {
        lowcost[i] = graph[1][i];//lowcost存放顶点1可达点的路径长度 
        mst[i] = 1;//初始化以1位起始点 
    }
    mst[1] = 0;
    for (i = 2; i <= n; i++)
    {
        min = MAXCOST;
        minid = 0;
        for (j = 2; j <= n; j++)
        {
            if (lowcost[j] < min && lowcost[j] != 0)
            {
                min = lowcost[j];//找出权值最短的路径长度 
                minid = j; //找出最小的ID 
            }
        }
        printf("V%d-V%d=%d\n", mst[minid], minid, min);
        sum += min;//求和 
        lowcost[minid] = 0;//该处最短路径置为0 
        for (j = 2; j <= n; j++)
        {
            if (graph[minid][j] < lowcost[j])//对这一点直达的顶点进行路径更新 
            {
                lowcost[j] = graph[minid][j];
                mst[j] = minid;
            }
        }
    }
    printf("Minimum weight sum=%d\n", sum);
}

int main()
{
    int i, j, k, m, n;
    int x, y, cost;
    printf("Please enter number of vertexes and edges:\n");
    scanf("%d%d", &m, &n);//m=顶点的个数，n=边的个数

    for (i = 1; i <= m; i++)//初始化图 
    {
        for (j = 1; j <= m; j++)
        {
            graph[i][j] = MAXCOST;
        }
    }
    printf("Please enter graph:\n");
    for (k = 1; k <= n; k++)
    {
        scanf("%d%d%d", &i, &j, &cost);
        graph[i][j] = cost;
        graph[j][i] = cost;
    }

    prim(graph, m);
    system("pause");
    return 0;
}
