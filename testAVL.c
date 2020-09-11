#include "AVL.h"
#include <stdio.h>
#include <process.h>

#define MAX_SIZE 100
int main()
{
    int insArr[MAX_SIZE] = {0};
    int number;
    printf("Please enter size , no greater than %d\n", MAX_SIZE);
    scanf("%d", &number);
    printf("Please enter the number to insert\n");
    for (int i = 0; i < number; ++i) {
        scanf("%d", insArr + i);
    }
	AVLTree tree = NULL;
	for (int i = 0; i < number; i++)
	{
		tree = Insert(insArr[i], tree);
	}
	printf("Inorder traverse\n");
	InOrderTraverse(tree);
	system("pause");
	return 0;
}