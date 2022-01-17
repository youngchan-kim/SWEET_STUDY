#include <stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include <string.h>

#define TURE 1
#define SUBJECT 3 

typedef struct Student
{
	char name[10];
	int age;
	char address[50];
	int kor;
	int eng;
	int math;
	struct Student* link;

}Student;

void Menu()
{
	printf("< < < = = = = 메뉴 = = = = > > >\n\n");
	printf("1.학생 등록\n");
	printf("2.학생 검색\n");
	printf("3.학생 목록\n");
	printf("4.학생 수정\n");
	printf("5.학생 삭제\n");
	printf("6.종료\n");
	printf("선택 : ");
}

void Studyinput(Student* tmp)
{
	system("cls");
	printf("학생 이름 입력 : ");
	scanf("%s", tmp->name);
	//printf("%s 학생 나이 입력 : ", tmp->name);
	//scanf("%d", &tmp->age);
	//printf("%s 학생 주소 입력 : ", tmp->name);
	//scanf("%s", tmp->address);
	//printf("%s 학생 국어 입력 : ", tmp->name);
	//scanf("%d", &tmp->kor);
	//printf("%s 학생 영어 입력 : ", tmp->name);
	//scanf("%d", &tmp->eng);
	//printf("%s 학생 수학 입력 : ", tmp->name);
	//scanf("%d", &tmp->math);
}
Student* StudyInsert(Student* head)
{
	if (head == NULL)
	{
		head = (Student*)malloc(sizeof(Student));
		Studyinput(head);
		head->link = NULL;

		return head;
	}
	head->link = StudyInsert(head->link);
	return head;
}


Student* FindName(Student* head, Student* tmp)
{
	char searchname[10];

	scanf("%s", searchname);
	tmp = head;
	while (tmp != NULL && strcmp(tmp->name, searchname) != 0)
	{
		tmp = tmp->link;
	}
	return tmp;
}
Student* StudyInformation(Student* head)
{
	Student* tmp;
	tmp = FindName(head, tmp);

	if (tmp == NULL)
		printf("입력한 학생이 없습니다.\n");
	else
	{
		int sum = tmp->kor + tmp->eng + tmp->math;
		float avg = (float)sum / SUBJECT;
		char grade;
		if (avg > 90)
			grade = 'A';
		else if (avg > 80 || avg <= 90)
			grade = 'B';
		else if (avg > 70 || avg <= 80)
			grade = 'C';
		else if (avg > 60 || avg <= 70)
			grade = 'D';
		else if (avg > 50 || avg <= 60)
			grade = 'E';
		else if (avg <= 50)
			grade = 'F';

		printf("< < = = = = = information = = = = = = > >\n\n");

		printf("학생 이름 : %s\n", tmp->name);
		printf("학생 나이 : %d 세\n", tmp->age);
		printf("학생 주소 : %s\n", tmp->address);
		printf("국어 점수 : %d 점\n", tmp->kor);
		printf("영어 점수 : %d 점\n", tmp->eng);
		printf("수학 점수 : %d 점\n", tmp->math);
		printf("합계 점수 : %d 점\n", sum);
		printf("학생 이름 : %2f 점\n", avg);
		printf("학생 이름 : %c 등급\n\n\n", grade);
		printf("학생 정보 검색 완료\n");
		return tmp;
	}
}

void StudyList(Student* head)
{
	Student* tmp;
	tmp = head;
	system("cls");
	printf("< < = = = = = information = = = = = = > >\n\n");
	printf("\t학생 이름\t 학생 나이\t 학생 주소\n");
	while (tmp != NULL)
	{
		printf("\t%s \t%d \t%s\n", tmp->name, tmp->age, tmp->address);
		tmp = tmp->link;
	}
	printf("학생 개개인의 점수는 검색을 이용하세요 !!\n");
	system("pause");
}

void StudyUpdateList(Student* tmp, int num)
{
	char updatename[10];
	char updateaddress[50];
	int updateage, updatekor, updateeng, updatemath;

	switch (num)
	{
	case 1:
		printf("현재 이름 : %s\n", tmp->name);
		printf("수정할 이름 : ");
		scanf("%s", updatename);
		printf("%s->", tmp->name);
		strcpy(tmp->name, updatename);
		printf("%s 로 수정 완료\n", updatename);
		system("pause");
		break;
	case 2:
		printf("현재 나이 : %d\n", tmp->age);
		printf("수정할 나이 : ");
		scanf("%d\n", &updateage);
		printf("%d->", tmp->age);
		tmp->age = updateage;
		printf("%d 로 나이 수정 완료", updateage);
		system("pause");
		break;
	case 3:
		printf("현재 주소 : %s\n", tmp->address);
		printf("수정할 주소 : ");
		scanf("%s\n", updateaddress);
		printf("%s->", tmp->address);
		strcpy(tmp->address, updateaddress);
		printf("%s 로 수정 완료", updateaddress);
		system("pause");
		break;
	case 4:
		printf("현재 점수\n 국어 : %d 영어 : %d 수학 : %d\n", tmp->kor, tmp->eng, tmp->math);
		printf("수정할 국어 점수 : ");
		scanf("%d\n", &updatekor);
		tmp->kor = updatekor;
		printf("수정할 영어 점수 : ");
		scanf("%d\n", &updateeng);
		tmp->eng = updateeng;
		printf("수정할 수학 점수 : ");
		scanf("%d\n", &updatemath);
		tmp->math = updatemath;
		printf("점수 수정 완료");
		system("pause");
		break;
	case 5:
		printf("수정을 종료합니다.\n");
		system("pause");
		return;
	}
}
void StudyUpdate(Student* head)
{
	int num;
	Student* tmp;
	printf("수정할 학생 이름은? ");
	tmp = StudyInformation(head);
	printf("수정할 항목을 선택 하시오\n");
	printf("1. 이름  2.나이  3.주소  4.점수  5.수정종료\n");
	printf("선택 : ");
	scanf("%d", &num);
	StudyUpdateList(tmp, num);
}
Student* StudyDelete(Student* head)
{
	Student* tmp;
	Student* savefront = NULL;
	Student* saveback;
	printf("삭제할 학생 이름 : ");
	char searchname[10];
	scanf("%s", searchname);

	tmp = head;
	while (tmp != NULL && strcmp(tmp->name, searchname) != 0)
	{
		savefront = tmp;
		tmp = tmp->link;
	}

	if (tmp == NULL)
		printf("해당 이름의 학생이 없습니다.\n");
	else
	{
		saveback = tmp->link;
		free(tmp);
		tmp = NULL;
		if (savefront == NULL)
		{
			head = saveback;
		}
		else
			savefront->link = saveback;
		printf("삭제 완료\n");
	}
	return head;
	system("pause");
}
void Relese(Student* head)
{
	if (head == NULL)
		return;
	Relese(head->link);
	free(head);
}

void main()
{
	int num;
	Student* head = NULL;
	//Student* tmp = NULL;

	while (TRUE)
	{
		system("cls");
		Menu();
		scanf("%d", &num);

		switch (num)
		{
		case 1:
			head = StudyInsert(head);
			break;
		case 2:
			system("cls");
			printf("검색할 이름 입력 : ");
			StudyInformation(head);

			system("pause");
			break;
		case 3:
			StudyList(head);
			break;
		case 4:
			StudyUpdate(head);
			break;
		case 5:
			head = StudyDelete(head);
			break;
		case 6:
			Relese(head);
			return;
		}
	}
}
