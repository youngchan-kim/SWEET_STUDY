#include<stdio.h>

void main()
{
	int Year, Num;
	printf("윤년이면1 윤년이 아니면 0을 출력\n");
	scanf("%d", &Year);

	if (Year % 4 == 0 && (Year % 100 != 0 || Year % 400 == 0))
		Num = 1;
	else
		Num = 0;

		
	printf("%d", Num);

}