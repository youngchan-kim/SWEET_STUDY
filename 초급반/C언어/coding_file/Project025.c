#include<stdio.h>

typedef struct people
{
	char Name[10];
	int Age;
	float Height;
}People;
// typedef : 자료형에 별명을 붙여주는 키워드


void main()
{
	People P1 = { "최정호", 20, 185.7f };
	printf("이름 = %s\n나이 = %d\n키=%.2f\n", P1.Name, P1.Age, P1.Height);
}