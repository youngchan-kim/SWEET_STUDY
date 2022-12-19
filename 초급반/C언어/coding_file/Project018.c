#include<stdio.h>

void main()
{
	int Num = 10, * pNum;
	char Ch = 'a', * pCh;

	pNum = &Num;
	pCh = &Ch;

	printf("pCh-1 = %p번지 pCh = %p번지 pCh+1 = %p번지\n", pCh - 1, pCh, pCh + 1);
	printf("Num-1 = %p번지 Num = %p번지 Num+1 = %p번지\n", pNum - 1, pNum, pNum + 1);
}