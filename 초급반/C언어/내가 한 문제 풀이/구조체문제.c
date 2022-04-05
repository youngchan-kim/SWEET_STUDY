#include<stdio.h>
#define LIMIT 5


typedef struct people
{
	char Name[10];
	int Age;
	float Height;
}People;

void ShowPeople(People P)
{
	printf("================\n");
	printf("1.이름 : %s\n", P.Name);
	printf("2.나이 : %d\n", P.Age);
	printf("3.키 : %.2f\n", P.Height);
	printf("================\n");
}

void main()
{
	int i = 0;
	People tmp = { "", 0, 00.0f };
	People P_List[LIMIT];
	for (i = 0; i < LIMIT; i++)
	{
		printf("======%d======\n", i + 1);
		printf("이름입력 :");
		scanf("%s", P_List[i].Name);
		printf("나이입력 :");
		scanf("%d", &P_List[i].Age);
		printf("키입력 :");
		scanf("%f", &P_List[i].Height);
		printf("===============\n");
	}
	for (int j = 0; j < LIMIT; j++)
	{
		i = LIMIT;
	for (int i = 0; i < LIMIT; i++)
		{
			if (i + 1 < LIMIT)
			{
				if (P_List[i].Age <0 P_List[i + 1].Age)
				{
					tmp = P_List[i];
					P_List[i] = P_List[i + 1];
					P_List[i + 1] = tmp;

				}
				else if (P_List[i].Age == P_List[i + 1].Age)
				{
					if (P_List[i].Height < P_List[i + 1].Height)
					{
						tmp = P_List[i];
						P_List[i] = P_List[i + 1];
						P_List[i + 1] = tmp;
					}
				}
			}
		}
	}
	for (i = 0; i < LIMIT; i++)
	{
		ShowPeople(P_List[i]);
	}

}