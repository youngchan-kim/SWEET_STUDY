#include<stdio.h>
#include<stdlib.h>

void main()
{
	int* pNumArr;
	int Size;
	printf("�Ҵ��� ������ ������ �Է��Ͻÿ� : ");
	scanf("%d", &Size);
	pNumArr = (int*)malloc(sizeof(int) * Size);
	for (int i = 0; i < Size; i++)
		pNumArr[i] = i + 1;
	for (int i = 0; i < Size; i++)
		printf("%d = %d\n", i, pNumArr[i]);
	free(pNumArr);
	pNumArr = NULL;
}