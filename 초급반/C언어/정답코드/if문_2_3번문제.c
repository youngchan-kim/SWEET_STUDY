#include<stdio.h>

void main()
{
	int Num, Cash, Sum;

	printf("구매할 도시락 갯수를 입력하시오 : ");
	scanf("%d", &Num);
	
	if (Num <= 10)
	{
		Cash = Num * 2500;
	}
	else
	{
		Num = Num - 10;
		Cash = Num * 2400;
		Cash = Cash + 25000;
	}
	printf("도시락 %d개 가격 : %d원", Num, Cash);
	
}