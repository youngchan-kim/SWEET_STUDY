#include<stdio.h>

void main()
{
	int Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, Num10, Num11, Num12;
	printf("1. 정수를 입력하시오 : ");
	scanf("%d", &Num1);
	if (Num1 % 3 == 0)
	{
		printf("%d는(은) 3의 배수입니다.\n", Num1);
	}
	if (Num1 % 3 != 0)
	{
		printf("%d는(은) 3의 배수 가 아닙니다.\n", Num1);
	}

	printf("2. 정수를 입력하시오 : ");
	scanf("%d", &Num2);
	if (Num2 > 0)
	{
		printf("%d의 절대값은 %d입니다.\n", Num2, Num2);
	}
	if (Num2 <= 0)
	{
		printf("%d의 절대값은 %d입니다.\n", Num2, -Num2);
	}

	printf("3. 정수를 입력하시오 : ");
	scanf("%d", &Num3);
	if (Num3 % 2 == 0)
	{
		printf("%d는 짝수 입니다.\n", Num3);
	}
	if (Num3 % 2 != 0)
	{
		printf("%d는 홀수 입니다.\n", Num3);
	}

	printf("4. 정수 두개를 입력하시오 : ");
	scanf("%d%d", &Num4, &Num5);
	if (Num4 > Num5)
	{
		printf("Max = %d\n", Num4);
	}
	if (Num4 <= Num5)
	{
		printf("Max = %d\n", Num5);
	}

	printf("5. 정수 세개를 입력하시오 : ");
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

	printf("6. 정수 두개를 입력하시오 : ");
	scanf("%d%d", &Num9, &Num10);
	if (Num9 > Num10)
	{
		if (Num9 % 2 == 0)
		{
			printf("큰수는 %d이며 짝수 입니다.\n", Num9);
		}
		if (Num9 % 2 != 0)
		{
			printf("큰수는 %d이며 홀수 입니다.\n", Num9);
		}
	}
	if (Num10 > Num9)
	{
		if (Num10 % 2 == 0)
		{
			printf("큰수는 %d이며 짝수 입니다.\n", Num10);
		}
		if (Num10 % 2 != 0)
		{
			printf("큰수는 %d이며 홀수 입니다.\n", Num10);
		}
	}

	printf("7. 정수 두개를 입력하시오 : ");
	scanf("%d%d", &Num11, &Num12);
	if ((Num11 + Num12) % 3 == 0)
	{
		printf("%d와 %d의 합 : %d 홀수이며 3의 배수입니다.", Num11, Num12, Num11 + Num12);
	}
	if ((Num11 + Num12) % 3 != 0)
	{
		printf("해당사항이 없습니다.");
	}


}