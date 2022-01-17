#include<stdio.h>

void main()
{
	int Num1, Kor, Math, Eng, Sum, Num2, Num3, Num4, Num5;
	float Evg;
	printf("1.정수를 입력하시오. : ");
	scanf("%d", &Num1);
	(Num1 % 5 == 0) ? printf("%d 는(은) 5의 배수입니다.\n", Num1) : printf("%d 는(은) 5의 배수가 아닙니다.\n", Num1);

	printf("2. 세과목의 점수를 입력하시오.\n");
	printf("국어 점수 : ");
	scanf("%d\n", &Kor);

	printf("수학 점수 : ");
	scanf("%d\n", &Math);

	printf("영어 점수 : ");
	scanf("%d\n", &Eng);

	Sum = Kor + Math + Eng;
	Evg = (float)Sum / 3;

	(Evg >= 60) ? printf("평균 %.2f 합격\n", Evg) : printf("평균 %.2f 불합격\n", Evg);

	printf("3. 두 정수를 입력하시오. : ");
	scanf("%d%d\n", &Num2, &Num3);

	(Num2 > Num3) ? printf("큰 수 %d\n", Num2) : printf("큰 수 %d\n", Num3);

	printf("4. 정수를 입력하시오. : ");

	scanf("%d\n", &Num4);
	(Num4 % 3 == 0 && Num4 % 2 == 0) ? printf("%d는 짝수이며 3의 배수 입니다.\n", Num4) : printf("조건 실패\n");
	
	printf("5. 정수를 입력하시오. : ");

	scanf("%d\n", &Num5);
	(Num5 % 5 == 0 || Num5 % 7 == 0) ? printf("%d는 5의 배수 이거나 7의 배수입니다.\n", Num5) : printf("조건 실패\n");
	

	
	printf("연산 수행\n");
	
	printf("%d & %d = %d\n", 12, 5, 12 & 5);
	printf("%d | %d = %d\n", 18, 3, 18 | 3);
	printf("%d ^ %d = %d\n", 14, 2, 14 ^ 2);
	printf("~20 = ~%d\n", ~20);
	printf("7 << 2 %d\n", 7 << 2);
	printf("40 >> 3 %d\n", 40 >> 3);

}