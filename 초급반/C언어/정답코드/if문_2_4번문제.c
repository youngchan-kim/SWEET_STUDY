#include<stdio.h>

void main()
{
	int Dsc, Cash, Sale;
	printf("������ ���� ������ �Է��Ͻÿ� : ");
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

	printf("���� %d�� ���� : %d��", Dsc, Cash);

}