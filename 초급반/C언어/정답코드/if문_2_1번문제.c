#include<stdio.h>

void main()
{
	int Kor, Eng, Math, Sum;
	float Avg;
	printf("1번 문제\n");
	printf("세과목의 성적을 입력하시오 \n");
	printf("국어 : ");
	scanf("%d", &Kor);
	printf("수학 : ");
	scanf("%d", &Math);
	printf("영어 : ");
	scanf("%d", &Eng);
	Sum = Eng + Kor + Math;
	Avg = (float)(Sum) / 3.0;

	printf("국어점수 : %d  수학점수 : %d  영어 점수 : %d\n", Kor, Math, Eng);
	printf("총합점수 : %d  평균점수 : %.2f  ", Sum, Avg);
	if (Avg >= 90)
		printf("등급 : A");
	else if (Avg < 90 && Avg >= 80)
		printf("등급 : B");
	else if (Avg < 80 && Avg >= 70)
		printf("등급 : C");
	else if (Avg < 70 && Avg >= 60)
		printf("등급 : D");
	else
		printf("등급 : F");

	
}