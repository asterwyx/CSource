#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define NUMBER 8000
#define THRD_NUM 5
// 全局变量
int g_iSum = 0;
HANDLE hThread[THRD_NUM];
CRITICAL_SECTION cs;

DWORD WINAPI Accumulate(LPVOID lpParam)
{
    for (int i = 0; i < NUMBER; i++)
    {
        EnterCriticalSection(&cs);
        int iCopy = g_iSum;
        g_iSum = iCopy + 1;
        LeaveCriticalSection(&cs);
        // g_iSum++;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    InitializeCriticalSection(&cs);
    for (int i = 0; i < THRD_NUM; i++)
    {
        hThread[i] = CreateThread(NULL, 0, Accumulate, NULL, 0, NULL);
    }
    WaitForMultipleObjects(THRD_NUM, hThread, TRUE, INFINITE);
    printf("    g_iSum = %d.\n", g_iSum);
    system("pause");
    return 0;
}
