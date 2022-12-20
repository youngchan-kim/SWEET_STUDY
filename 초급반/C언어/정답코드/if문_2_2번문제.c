#include<stdio.h>

void main()
{
	int Time, Cash, Num, Temp;
	float Avg;
	printf("승마 이용 시간을 입력하시오 :");
	scanf("%d", &Time);
	
	if (Time <= 30)
	{
		Cash = 3000;
	}
	else if (Time > 30 && Time % 10 == 0)
	{
		Temp = Time - 30;
		Num = Temp / 10;
		Cash = 3000 + Num * 500;
	}
	else 
	{
		Temp = Time - 20;
		Num = Temp / 10;
		Cash = 3000 + Num * 500;
	}
	printf("%d분 탑승 요금 : %d", Time, Cash);
}