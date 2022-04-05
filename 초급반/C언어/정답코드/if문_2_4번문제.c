#include<stdio.h>

void main()
{
	int Dsc, Cash, Sale;
	printf("구매할 디스켓 갯수를 입력하시오 : ");
	scanf("%d", &Dsc);
	
	if (Dsc < 10)
	{
		Cash = Dsc * 5000;
	}
	else if (Dsc >= 10 && Dsc < 100)
	{
		Cash = Dsc * 5000;
		Sale = (Cash / 100) * 10;
		Cash = Cash - Sale;
	}
	else if (Dsc >= 100)
	{
		Cash = Dsc * 5000;
		Sale = (Cash / 100) * 12;
		Cash = Cash - Sale;
	}

	printf("디스켓 %d개 가격 : %d원", Dsc, Cash);

}