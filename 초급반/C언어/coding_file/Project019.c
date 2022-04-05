#include<stdio.h>

void main()
{
	int Num =10, *pNum;
	char Ch = 'a', * pCh;

	pNum = &Num;
	pCh = &Ch;

	printf("char 자료형의 크기 = %d\n", sizeof(Ch));
	printf("int 자료형의 크기 = %d\n", sizeof(Num));
	printf("char* 자료형의 크기 = %d\n", sizeof(pCh));
	printf("int* 자료형의 크기 = %d\n", sizeof(pNum));
}