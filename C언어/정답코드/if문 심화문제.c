#include<stdio.h>

void main()
{
	int Year, Num;
	printf("�����̸�1 ������ �ƴϸ� 0�� ���\n");
	scanf("%d", &Year);

	if (Year % 4 == 0 && (Year % 100 != 0 || Year % 400 == 0))
		Num = 1;
	else
		Num = 0;

		
	printf("%d", Num);

}