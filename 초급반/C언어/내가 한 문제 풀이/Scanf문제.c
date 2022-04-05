#include<stdio.h>

void main() 
{
	char str1, nstr;
	int num1;
	float Fnum, avg;
	int Kor, Math, Eng, sum;
	char Name[30];
	int Age;
	printf("====1번 문제====\n");
	printf("단일문자를 입력하시오 : ");
	scanf("%c", &str1);
	printf("정수를 입력하시오 : ");
	scanf("%d", &num1);
	nstr = str1 + num1;
	printf("%c + %d = %c\n", str1, num1, nstr);

	printf("====2번 문제====\n");
	printf("소숫점수를 입력하시오 :");
	scanf("%f", &Fnum);
	printf("소숫점수 : %.2f\n", Fnum);

	printf("====3번 문제====\n");
	printf("국어점수를 입력하시오 : ");
	scanf("%d", &Kor);
	printf("수학점수를 입력하시오 : ");
	scanf("%d", &Math);
	printf("영어점수를 입력하시오 : ");
	scanf("%d", &Eng);

	printf("국어점수 : %d\n", Kor);
	printf("수학점수 : %d\n", Math);
	printf("영어점수 : %d\n", Eng);
	sum = Kor + Math + Eng;
	avg = (float)sum / 3;
	printf("합계점수 : %d  평균점수 : %f\n", sum, avg);

	printf("====4번 문제====\n");
	printf("이름을 입력하시오 : ");
	scanf("%s", Name);
	printf("%s님의 나이를 입력하시오 : ", Name);
	scanf("%d", &Age);
	printf("%s님의 나이는 %d세 입니다.", Name, Age);


}