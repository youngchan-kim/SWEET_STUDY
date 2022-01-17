#include<stdio.h>
#include<stdlib.h>

void main()
{
	int* pNum = (int*)malloc(sizeof(int));
	*pNum = 10;
	printf("pNumÁÖ¼Ò = %p\npNum°ª = %d", pNum, *pNum);
	free(pNum);
}