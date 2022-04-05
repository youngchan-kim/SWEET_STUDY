#include<stdio.h>
#include<stdlib.h>

void main()
{
	int* pNum = (int*)malloc(sizeof(int));
	*pNum = 10;
	printf("pNum林家 = %p\npNum蔼 = %d", pNum, *pNum);
	free(pNum);
	*pNum = 20;
	printf("pNum林家 = %p\npNum蔼 = %d", pNum, *pNum);
}