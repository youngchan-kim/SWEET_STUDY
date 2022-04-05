#include<stdio.h>

void main()
{
	int Num;
	int *pNum = &Num;
	*pNum = 10;
	printf("Num의 주소 = %p\n", &Num);
	printf("pNum이 가지고 있는 값 = %p\n", pNum);
	printf("Num = %d\n", Num);
	printf("*pNum = %d\n", *pNum);
	printf("*pNum의 주소 = %p", *pNum);

}