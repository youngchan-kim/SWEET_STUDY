#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
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
	printf("======%s학생(%d번)======\n", St->Name, St->Number);
	printf("나이 : %d,  성별 : %s,  학년 : %d\n", St->Age, St->Gender, St->Class);
	printf("======================\n");
}
void SetStudent(Student* St, int* StudentCount)
{
	system("cls");
	St->Number = ++(*StudentCount);
	printf("======%d번 학생======\n", St->Number);
	printf("이름 입력 : ");
	scanf("%s", St->Name);
	printf("나이 입력 : ");
	scanf("%d", &St->Age);
	printf("성별 입력 : ");
	scanf("%s", St->Gender);
	printf("학년 입력(1~3) : ");
	scanf("%d", &St->Class);
	if ((*St).Class < 1 || &St->Class > 3)
	{
		do
		{
			printf("학년 잘못 입력 (범위 1~3학년)\n");
			system("pause");

			printf("학년 입력(1~3) : ");
			scanf("%d", &St->Class);
		} while (&St->Class < 1 || &St->Class > 3);
	}

}
void ShowStudentClass(Student* St, int* StudentCount)
{
	scanf("%d", St->Class);
	printf("┌─────────1 학년─────────┐");
	for (int i = 0; i < StudentCount; i++)
	{
		if (strcmp(St->Class, St->Class))
		{
			St->Number = ++(*StudentCount);
			printf("======%s학생(%d번)======\n", St->Name, St->Number);
			printf("나이 : %d,  성별 : %s,  학년 : %d\n", St->Age, St->Gender, St->Class);
			printf("======================\n");
		}
	}
	printf("──────────────────────────┘");
}

void ShowStudentName(Student* St, int* StudentCount)
{
	scanf("%d", St->Name);
	printf("┌─────────1 학년─────────┐");
	for (int i = 0; i < StudentCount; i++)
	{
		if (strcmp(St->Name, St->Name))
		{
			St->Number = ++(*StudentCount);
			printf("======%s학생(%d번)======\n", St->Name, St->Number);
			printf("나이 : %d,  성별 : %s,  학년 : %d\n", St->Age, St->Gender, St->Class);
			printf("======================\n");
		}
	}
	printf("──────────────────────────┘");
}

void main()
{
	Student* Student_List[MAX];
	int Select;
	int StudentCount = 0;

	while (1)
	{
		system("cls");
		printf("=====학생관리프로그램=====(총 인원 : %d)\n", StudentCount);
		printf("1.학생 등록\n");
		printf("2.학생 목록(번호순)\n");
		printf("3.학생 목록(학년순)\n");
		printf("4.학년 검색\n");
		printf("5.학생 검색\n");
		printf("6.마지막 학생 삭제\n");
		printf("7.학생 전체 삭제\n");
		printf("8.종료\n");
		printf("입력 : ");
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			//StudentRegistration()
			if (StudentCount + 1 >= MAX)
			{
				printf("학생정원(50명)이 모두 찼습니다.\n");
				system("pause");
				break;
			}
			Student_List[StudentCount] = (Student*)malloc(sizeof(Student));
			SetStudent(Student_List[StudentCount], &StudentCount);
			break;
		case 2:

			for (int i = 0; i < StudentCount; i++)
				ShowStudent(Student_List[i]);
			system("pause");
			break;
		case 3:

		case 4:
			printf("검색할 학년 입력 : ");
			ShowStudentClass(Student_List, StudentCount);
			system("pause");
			break;
		case 5:
			printf("검색할 학년 입력 : ");
			ShowStudentName(Student_List, StudentCount);
			system("pause");
			break;
		case 6:

		case 7:

			return;
		}
	}
}