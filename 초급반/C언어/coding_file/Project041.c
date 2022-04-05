#include<stdio.h>

typedef struct people
{
	char Name[10];
	int Age;
	char PhonNumber[20];
}People;

void main()
{
	People P1 = { "A", 20, "010-1234-5678" };
	FILE* f = fopen("People.txt", "w");
	char buf[256] = { 0 };
	fprintf(f, "이름 : %s 나이 : %d\n", P1.Name, P1.Age);
	fprintf(f, "휴대폰 번호 : %s", P1.PhonNumber);
	fclose(f);
	f = fopen("People.txt", "r");
	if (f == NULL)
		printf("해당 이름의 파일이 없습니다.");
	else
	{
			fread(buf, sizeof(buf), 1, f);
			printf("%s\n", buf);
	}
	fclose(f);
}