#include<map>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

#define TRUE 1
#define NULL 0

typedef struct node
{
	char name[20];
	char add[20];
	int sum, kor, eng, mat, age;
	float abs;
	char grade;
}node;

void PrintList(std::map<int, node> StudentMap)
{
	if (StudentMap.empty())
	{
		printf("\n<학생 개개인의 점수는 검색을 이용하세요 !!>\n");
		return;
	}
	else
	{
		for (std::map<int, node> ::iterator iter = StudentMap.begin(); iter != StudentMap.end(); iter++)
			printf("%10d%10s%10d%10s\n", iter->first, iter->second.name, iter->second.age, iter->second.add);
		printf("\n");
	}
}

void SetGrade(node* head)
{
	head->sum = (head->eng) + (head->kor) + (head->mat);
	head->abs = head->sum / 3;
	if (head->abs > 90)
		head->grade = 'A';
	else if (head->abs > 80)
		head->grade = 'B';
	else if (head->abs > 70)
		head->grade = 'C';
	else if (head->abs > 60)
		head->grade = 'D';
	else
		head->grade = 'F';
}

node create()
{
	node head;
	printf("학생 이름 입력 : ");
	scanf("%s", head.name);
	printf("%s 학생 나이 입력 : ", head.name);
	scanf("%d", &head.age);
	printf("%s 학생 주소 입력 : ", head.name);
	scanf("%s", head.add);
	printf("%s 학생 국어 입력 : ", head.name);
	scanf("%d", &head.kor);
	printf("%s 학생 영어 입력 : ", head.name);
	scanf("%d", &head.eng);
	printf("%s 학생 수학 입력 : ", head.name);
	scanf("%d", &head.mat);
	SetGrade(&head);
	return head;
}

void ShowStudent(std::map<int, node>::iterator findIter)
{
	printf("< = = = = = information = = = = = = >\n");
	printf("학번 : %d\n", findIter->first);
	printf("학생 이름 : %s\n", findIter->second.name);
	printf("학생 나이 : %d 세\n", findIter->second.age);
	printf("학생 주소 : %s\n", findIter->second.add);
	printf("국어 점수 : %d\n", findIter->second.kor);
	printf("영어 점수 : %d\n", findIter->second.eng);
	printf("수학 점수 : %d\n", findIter->second.mat);
	printf("합계 점수 : %d\n", findIter->second.sum);
	printf("평균 점수 : %.2f\n", findIter->second.abs);
	printf("등급 : %c\n", findIter->second.grade);
}

void SearchData(std::map<int, node> StudentMap, int num)
{
	std::map<int, node>::iterator findIter = StudentMap.find(num);
	if (findIter != StudentMap.end())
	{
		printf("학생 정보 검색 완료\n");
		ShowStudent(findIter);

	}
	else
		printf("%d 찾을 수 없습니다.\n", num);
}

void modify(std::map<int, node>* StudentMap, int num)
{
	int listnum, tempnum;
	char modifystring[20];
	node head;
	std::map<int, node>::iterator findIter = StudentMap->find(num);
	if (findIter != StudentMap->end())
	{
		while (TRUE)
		{
			system("cls");
			printf("학생 정보 검색 완료\n");
			ShowStudent(findIter);
			printf("\n\n");
			printf("수정할 항목을 선택하시오\n");
			printf("1.이름  2.나이  3.주소  4.점수  5.수정종료\n");
			scanf("%d", &listnum);
			switch (listnum)
			{
			case 1:
				printf("현재이름 : %s\n", findIter->second.name);
				strcpy(modifystring, findIter->second.name);
				printf("수정할 이름 : ");
				scanf("%s", findIter->second.name);
				printf("%s -> %s 로 이름 수정 완료\n", modifystring, findIter->second.name);
				break;
			case 2:
				printf("현재 나이 : %d\n", findIter->second.age);
				tempnum = findIter->second.age;
				printf("수정할 나이 : ");
				scanf("%d", &findIter->second.age);
				printf("%d -> %d 로 이름 수정 완료\n", tempnum, findIter->second.age);
				break;
			case 3:
				printf("현재 주소 : %s\n", findIter->second.add);
				strcpy(modifystring, findIter->second.add);
				printf("수정할 주소 : ");
				scanf("%s", findIter->second.add);
				printf("%s -> %s 로 주소 수정 완료\n", modifystring, findIter->second.add);
				break;
			case 4:
				printf("현재 점수\n");
				printf("국어 : %d\t영어 : %d\t수학 : %d\n", findIter->second.kor, findIter->second.eng, findIter->second.mat);
				printf("수정할 국어 점수 : ");
				scanf("%d", &head.kor);
				findIter->second.kor = head.kor;
				printf("수정할 영어 점수 : ");
				scanf("%d", &head.eng);
				findIter->second.eng = head.eng;
				printf("수정할 수학 점수 : ");
				scanf("%d", &head.mat);
				findIter->second.mat = head.mat;
				SetGrade(&head);
				findIter->second.sum = head.sum;
				findIter->second.abs = head.abs;
				findIter->second.grade = head.grade;
				printf("점수 수정 완료\n");
				break;
			case 5:
				printf("수정을 종료합니다\n");
				return;
			}
		}
	}
	else
		printf("%s 찾을 수 없습니다.\n", num);
}

void DeleteData(std::map<int, node>* StudentMap, int num)
{
	std::map<int, node>::iterator findIter = StudentMap->find(num);
	if (findIter != StudentMap->end())
		StudentMap->erase(findIter);

	else
		printf("Data %d Not Found!\n", num);
}

void main()
{
	int StudentNumber;
	std::map<int, node> StudentMap;
	std::map<int, node>::iterator findIter;
	int num;
	char name[20];
	while (TRUE)
	{
		system("cls");
		printf("< < < = = = = 메뉴 = = = = > > >\n\n");
		printf("1.학생 등록\n");
		printf("2.학생 검색\n");
		printf("3.학생 목록\n");
		printf("4.학생 수정\n");
		printf("5.학생 삭제\n");
		printf("6.종     료\n");
		printf("선  택 : ");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			printf("학번을 입력해주세요. : ");//중복된 학번인지 아닌지
			scanf("%d", &StudentNumber);
			findIter = StudentMap.find(StudentNumber);
			if (findIter != StudentMap.end())
				printf("학번이 중복 되었습니다.\n");
			else
			{
				printf("[ %d ] 해당 학번을 사용 할 수 있습니다.\n", StudentNumber);
				StudentMap.insert(std::make_pair(StudentNumber, create()));
				printf("학생 정보 입력 완료\n");
			}
			system("pause");
			break;
		case 2:
			printf("학번 입력 : ");
			scanf("%d", &num);
			SearchData(StudentMap, num);
			system("pause");
			break;
		case 3:
			printf("%10s%10s%10s%10s\n", "학    번", "학생이름", "학생나이", "학생주소");
			PrintList(StudentMap);
			system("pause");
			break;
		case 4:
			system("cls");
			printf("수정할 학     번: ");
			scanf("%d", &num);
			modify(&StudentMap, num);
			break;
		case 5:
			printf("삭제할 학     번 입력 : ");
			scanf("%d", &num);
			DeleteData(&StudentMap, num);
			break;
		case 6:
			StudentMap.clear();
			return;
		}
	}
}