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
		printf("�ش� �̸��� ������ �����ϴ�.");
	else
	{
		fscanf(f, "%s", P1.Name);
		fscanf(f, "%d", &P1.Age);
		fscanf(f, "%s", P1.PhonNumber);
		printf("�̸� : %s \n���� : %d\n", P1.Name, P1.Age);
		printf("�޴��� ��ȣ : %s\n", P1.PhonNumber);
		fclose(f);
	}
}