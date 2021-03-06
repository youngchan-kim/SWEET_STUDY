#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#define MAX 50

typedef struct student
{
	char Name[10];
	int Age;
	int Class;
	int Number;
	char Gender[10];
}Student;


void ShowStudent(Student* St)
{
	printf("    ======%s학생(%d번)======\n", St->Name, St->Number);
	printf("    나이 : %d,  성별 : %s,  학년 : %d\n", St->Age, St->Gender, St->Class);
	printf("    ======================\n");
}

void ShowClass(Student* St[], int Class, int StudentCount)
{
	printf("┌─────────%d 학년─────────┐\n", Class);
	for (int i = 0; i < StudentCount; i++)
	{
		if (St[i]->Class == Class)
			ShowStudent(St[i]);
	}
	printf("└─────────────────────┘\n");
}

int SetStudent(Student* St, int Number)
{
	St->Number = ++Number;
	printf("======%d번 학생======\n", St->Number);
	printf("이름 입력 : ");
	scanf("%s", St->Name);
	printf("나이 입력 : ");
	scanf("%d", &St->Age);
	printf("성별 입력 : ");
	scanf("%s", St->Gender);
	while (1)
	{
		printf("학년 입력(1~3) : ");
		scanf("%d", &St->Class);
		if (St->Class <= 3 && St->Class >= 1)
			break;
		printf("학년 잘못 입력(범위 1~3학년)\n");
		system("pause");
	}
	return Number;
}


void main()
{
	int StudentCount = 0;
	Student* Student_List[MAX];
	int Select;
	char tmp[10];
	while (1)
	{
		system("cls");
		printf("=====학생관리프로그램=====(총 인원 : %d)\n", StudentCount);
		printf("   1.학생 등록\n");
		printf("   2.학생 목록(번호순)\n");
		printf("   3.학생 목록(학년순)\n");
		printf("   4.학년 검색\n");
		printf("   5.학생 검색\n");
		printf("   6.마지막 학생 삭제\n");
		printf("   7.학생 전체 삭제\n");
		printf("   8.종료\n");
		printf("   입력 : ");
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			system("cls");
			if (StudentCount + 1 >= MAX)
			{
				printf("학생정원(%d명)이 모두 찼습니다.\n", MAX);
				system("pause");
				break;
			}
			Student_List[StudentCount] = (Student*)malloc(sizeof(Student));
			StudentCount = SetStudent(Student_List[StudentCount], StudentCount);
			break;
		case 2:
			system("cls");
			for (int i = 0; i < StudentCount; i++)
				ShowStudent(Student_List[i]);
			system("pause");
			break;
		case 3:
			system("cls");
			for (int i = 1; i <= 3; i++)
				ShowClass(Student_List, i, StudentCount);
			system("pause");
			break;
		case 4:
			system("cls");
			while (1)
			{
				printf("검색할 학년 입력(1~3) : ");
				scanf("%d", &Select);
				if (Select <= 3 && Select >= 1)
					break;
				printf("학년 잘못 입력(범위 1~3학년)\n");
				system("pause");
			}
			ShowClass(Student_List, Select, StudentCount);
			system("pause");
			break;
		case 5:
			system("cls");
			printf("검색할 이름 입력 : ");
			scanf("%s", tmp);
			for (int i = 0; i < StudentCount; i++)
			{
				if (strcmp(Student_List[i]->Name, tmp) == 0)
					ShowStudent(Student_List[i]);
			}
			system("pause");
			break;
		case 6:
			if (StudentCount - 1 < 0)
			{
				printf("더 이상 삭제할 학생이 없습니다.\n");
				system("pause");
				break;
			}
			StudentCount--;
			ShowStudent(Student_List[StudentCount]);
			printf("삭제 완료");
			free(Student_List[StudentCount]);
			Student_List[StudentCount] = NULL;
			break;
		case 7:
			for (int i = 0; i < StudentCount; i++)
			{
				ShowStudent(Student_List[i]);
				printf("삭제 완료");
				free(Student_List[i]);
				Student_List[i] = NULL;
			}
			StudentCount = 0;
			break;
		case 8:
			for (int i = 0; i < StudentCount; i++)
			{
				printf("%s학생 동적할당 해제 완료\n", Student_List[i]->Name);
				free(Student_List[i]);
			}
			return;
		}
	}
}