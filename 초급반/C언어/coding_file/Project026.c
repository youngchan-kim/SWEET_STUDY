#include<stdio.h>

typedef struct people
{
	char Name[10];
	int Age;
	float Height;
}People;

void ShowPeople(People P)
{
	printf("================\n");
	printf("1.�̸� : %s\n", P.Name);
	printf("2.���� : %d\n", P.Age);
	printf("3.Ű : %.2f\n", P.Height);
	printf("================\n");
}

void main()
{
	People P_List[3];
	for (int i = 0; i < 3; i++)
	{
		printf("==%d��° ���==\n", i+1);
		printf("�̸��Է� :");
		scanf("%s", P_List[i].Name);
		printf("�����Է� :");
		scanf("%d", &P_List[i].Age);
		printf("Ű�Է� :");
		scanf("%f", &P_List[i].Height);
		printf("===============\n");
	}
	for (int i = 0; i < 3; i++)
		ShowPeople(P_List[i]);
}