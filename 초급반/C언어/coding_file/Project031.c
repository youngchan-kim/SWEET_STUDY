#include<stdio.h>
#include<stdlib.h>

void main()
{
	int* pNum = (int*)malloc(sizeof(int));
	*pNum = 10;
	printf("pNum�ּ� = %p\npNum�� = %d", pNum, *pNum);
	free(pNum);
	*pNum = 20;
	printf("pNum�ּ� = %p\npNum�� = %d", pNum, *pNum);
}