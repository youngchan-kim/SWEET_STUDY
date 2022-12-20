#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>

#define MAX 50
#define TMPNUM 1

#define Gradeone 1
#define Gradethree 3

#define TRUE 1

#define NAMEMAX 10
typedef struct student
{
	char Name[NAMEMAX];
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
	printf("성별 입력 : (남~여)");
	scanf("%s", St->Gender);
	printf("학년 입력(1~3) : ");
	scanf("%d", &St->Class);
	if (St->Class < Gradeone || St->Class > Gradethree)
	{
		do
		{
			printf("학년 잘못 입력(범위 1~3학년)\n");
			system("pause");
			printf("학년 입력(1~3) : ");
			scanf("%d", &St->Class);
		} while (St->Class < Gradeone || St->Class > Gradethree);
	}
}

void FullLoop(Student* St[MAX], int StudentCount)
{
	system("cls");
	for (int i = 0; i < StudentCount; i++)
		ShowStudent(St[i]);
}

void ClassSort(Student* St[MAX], int StudentCount, int searchclass)
{
	printf("┌─────────%d 학년─────────┐\n", searchclass);
	for (int i = 0; i < StudentCount; i++)
	{
		if (St[i]->Class == searchclass)
		{
			ShowStudent(St[i]);
		}
	}
	printf("└─────────────────────┘\n");
}

void ClassSearch(Student* St[MAX], int StudentCount)
{
	system("cls");
	int searchclass;
	printf("검색할 학년 입력(1~3) : ");
	scanf("%d", &searchclass);
	ClassSort(St, StudentCount, searchclass);
}

void NameSearch(Student* St[MAX], int StudentCount)
{
	system("cls");
	char searchname[NAMEMAX];
	printf("검색할 학생 입력 : ");
	scanf("%s", &searchname);

	for (int i = 0; i < StudentCount; i++)
	{
		if (strcmp(St[i]->Name, searchname) == 0)
		{
			ShowStudent(St[i]);
		}
	}
}
void LastStudentDelet(Student* St[MAX], int* StudentCount)
{
	free(St[*StudentCount - 1]);
	St[*StudentCount - 1] = NULL;
	--(*StudentCount);
}

void AllStudentDelet(Student* St[MAX], int* StudentCount)
{
	for (int i = 0; i < *StudentCount; i++)
	{
		free(St[i]);
		St[i] = NULL;
	}
	*StudentCount = 0;
}


void StudentSave(Student* St[MAX], int StudentCount)
{
	FILE* f = fopen("학생정보test.txt", "w");
	fprintf(f, "%d\n", StudentCount);
	for (int i = 0; i < StudentCount; i++)
	{
		fprintf(f, "%s %d %s %d\n", St[i]->Name, St[i]->Age, St[i]->Gender, St[i]->Class);
	}
	fclose(f);
	printf("저장 완료!!\n");
}

void StudentLoad(Student* St[MAX], int* StudentCount)
{
	int Count = 0;
	FILE* f = fopen("학생정보test.txt", "r");

	if (f == NULL)
		printf("해당 이름의 파일이 없습니다.");
	else
	{
		fscanf(f, "%d", Count);

		Count += *StudentCount;

		for (int i = *StudentCount; i < Count; i++)
		{
			if (i >= MAX)
			{
				printf("더 이상 학생을 불러올 수 없습니다.\n");
				system("pause");
				break;
			}
			St[i] = (Student*)malloc(sizeof(Student));
			St[i]->Number = ++(*StudentCount);
			fscanf(f, "%s", St[i]->Name);
			fscanf(f, "%d", &St[i]->Age);
			fscanf(f, "%s", St[i]->Gender);
			fscanf(f, "%d", &St[i]->Class);
		}

		fclose(f);

	}
}

void main()
{
	Student* Student_List[MAX];
	int Select;
	int StudentCount = 0;
	while (TRUE)
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
		printf("8.학생정보 저장\n");
		printf("9.학생정보 불러오기\n");
		printf("10.종료\n");
		printf("입력 : ");
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
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
			FullLoop(Student_List, StudentCount);
			system("pause");
			break;
		case 3:
			system("cls");
			for (int searchclass = 1; searchclass < 4; searchclass++)
			{
				ClassSort(Student_List, StudentCount, searchclass);
			}
			system("pause");
			break;
		case 4:
			ClassSearch(Student_List, StudentCount);
			system("pause");
			break;
		case 5:
			NameSearch(Student_List, StudentCount);
			system("pause");
			break;
		case 6:
			LastStudentDelet(Student_List, &StudentCount);
			break;
		case 7:
			AllStudentDelet(Student_List, &StudentCount);
			break;
		case 8:
			StudentSave(Student_List, StudentCount);
			system("pause");
			break;
		case 9:
			StudentLoad(Student_List, &StudentCount);
			break;
		case 10:
			AllStudentDelet(Student_List, &StudentCount);
			return;
		}
	}
}