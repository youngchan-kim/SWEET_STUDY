#include <stdio.h>
typedef struct people
{
	char Name[10];
	int Age;
	char PhonNumber[20];
}People;
void main()
{
	People P1 = { "A", 20, "010-1234-5678" };
	//FILE* f = fopen("People.txt", "w");
	/*fprintf(f, "%s %d %s", P1.Name, P1.Age, P1.PhonNumber);
	fclose(f);*/
	FILE* f = fopen("People.txt", "r");
	if (f == NULL)
		printf("해당 이름의 파일이 없습니다.");
	else
	{
		fscanf(f, "%s", P1.Name);
		fscanf(f, "%d", &P1.Age);
		fscanf(f, "%s", P1.PhonNumber);
		printf("이름 : %s \n나이 : %d\n", P1.Name, P1.Age);
		printf("휴대폰 번호 : %s\n", P1.PhonNumber);
		fclose(f);
	}
}