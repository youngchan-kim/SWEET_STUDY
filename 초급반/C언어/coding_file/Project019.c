#include<stdio.h>

void main()
{
	int Num =10, *pNum;
	char Ch = 'a', * pCh;

	pNum = &Num;
	pCh = &Ch;

	printf("char �ڷ����� ũ�� = %d\n", sizeof(Ch));
	printf("int �ڷ����� ũ�� = %d\n", sizeof(Num));
	printf("char* �ڷ����� ũ�� = %d\n", sizeof(pCh));
	printf("int* �ڷ����� ũ�� = %d\n", sizeof(pNum));
}