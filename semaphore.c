#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define THRD_NUM 3
HANDLE hTest;

DWORD WINAPI AccessDB(LPVOID lpParam)
{
    while (TRUE)
    {
        WaitForSingleObject(hTest, 100);
        printf("Do database access!\n");
        printf("Done.\n");
        ReleaseSemaphore(hTest, 1, NULL);
        Sleep(1000);
    }
}
int main()
{
    hTest = CreateSemaphore(NULL, 2, 2, "Test");
    HANDLE hThread[THRD_NUM];
    
}