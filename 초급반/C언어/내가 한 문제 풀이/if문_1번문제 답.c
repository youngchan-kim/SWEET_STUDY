#include<stdio.h>

void main()
{
	int Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, Num10, Num11, Num12;
	printf("1. ������ �Է��Ͻÿ� : ");
	scanf("%d", &Num1);
	if (Num1 % 3 == 0)
	{
		printf("%d��(��) 3�� ����Դϴ�.\n", Num1);
	}
	if (Num1 % 3 != 0)
	{
		printf("%d��(��) 3�� ��� �� �ƴմϴ�.\n", Num1);
	}

	printf("2. ������ �Է��Ͻÿ� : ");
	scanf("%d", &Num2);
	if (Num2 > 0)
	{
		printf("%d�� ���밪�� %d�Դϴ�.\n", Num2, Num2);
	}
	if (Num2 <= 0)
	{
		printf("%d�� ���밪�� %d�Դϴ�.\n", Num2, -Num2);
	}

	printf("3. ������ �Է��Ͻÿ� : ");
	scanf("%d", &Num3);
	if (Num3 % 2 == 0)
	{
		printf("%d�� ¦�� �Դϴ�.\n", Num3);
	}
	if (Num3 % 2 != 0)
	{
		printf("%d�� Ȧ�� �Դϴ�.\n", Num3);
	}

	printf("4. ���� �ΰ��� �Է��Ͻÿ� : ");
	scanf("%d%d", &Num4, &Num5);
	if (Num4 > Num5)
	{
		printf("Max = %d\n", Num4);
	}
	if (Num4 <= Num5)
	{
		printf("Max = %d\n", Num5);
	}

	printf("5. ���� ������ �Է��Ͻÿ� : ");
	scanf("%d%d%d", &Num6, &Num7, &Num8);
	if (Num6 > Num7 && Num6 > Num8)
	{
		printf("Max = %d\n", Num6);
	}
	if (Num7 > Num6 && Num7 > Num8)
	{
		printf("Max = %d\n", Num7);
	}
	if (Num8 > Num6 && Num8 > Num7)
	{
		printf("Max = %d\n", Num8);
	}

	printf("6. ���� �ΰ��� �Է��Ͻÿ� : ");
	scanf("%d%d", &Num9, &Num10);
	if (Num9 > Num10)
	{
		if (Num9 % 2 == 0)
		{
			printf("ū���� %d�̸� ¦�� �Դϴ�.\n", Num9);
		}
		if (Num9 % 2 != 0)
		{
			printf("ū���� %d�̸� Ȧ�� �Դϴ�.\n", Num9);
		}
	}
	if (Num10 > Num9)
	{
		if (Num10 % 2 == 0)
		{
			printf("ū���� %d�̸� ¦�� �Դϴ�.\n", Num10);
		}
		if (Num10 % 2 != 0)
		{
			printf("ū���� %d�̸� Ȧ�� �Դϴ�.\n", Num10);
		}
	}

	printf("7. ���� �ΰ��� �Է��Ͻÿ� : ");
	scanf("%d%d", &Num11, &Num12);
	if ((Num11 + Num12) % 3 == 0)
	{
		printf("%d�� %d�� �� : %d Ȧ���̸� 3�� ����Դϴ�.", Num11, Num12, Num11 + Num12);
	}
	if ((Num11 + Num12) % 3 != 0)
	{
		printf("�ش������ �����ϴ�.");
	}


}