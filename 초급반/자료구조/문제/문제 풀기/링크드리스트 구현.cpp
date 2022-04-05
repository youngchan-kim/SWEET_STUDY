#include<list> 
#include<stdio.h>
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
	struct node* link;
}node;

void PrintList(std::list<node> iList)
{
	if (iList.empty())
	{
		printf("\n<학생 개개인의 점수는 검색을 이용하세요 !!>\n");
		return;
	}
	else
	{
		for (std::list<node>::iterator iter = iList.begin(); iter != iList.end(); iter++)
			printf("%10s%10d%10s\n", iter->name, iter->age, iter->add);
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

void ShowStudent(std::list<node>::iterator findIter)
{
	printf("< = = = = = information = = = = = = >\n");
	printf("학생 이름 : %s\n", findIter->name);
	printf("학생 나이 : %d 세\n", findIter->age);
	printf("학생 주소 : %s\n", findIter->add);
	printf("국어 점수 : %d\n", findIter->kor);
	printf("수학 점수 : %d\n", findIter->mat);
	printf("합계 점수 : %d\n", findIter->sum);
	printf("평균 점수 : %.2f\n", findIter->abs);
	printf("등급 : %c\n", findIter->grade);
}
//어디에 있는 값을 관리 할지 선택해서 관리해야한다.
std::list<node>::iterator Search(std::list<node>* iList, char* name)
{
	for (std::list<node>::iterator iter = iList->begin(); iter != iList->end(); iter++)
	{
		if (strcmp(iter->name, name) == 0)
			return iter;
	}
	return iList->end();
}

void SearchData(std::list<node>* iList, char* name)
{
	std::list<node>::iterator findIter = Search(iList, name);
	if (findIter != iList->end())
	{
		printf("학생 정보 검색 완료\n");
		ShowStudent(findIter);
	}
	else
		printf("%s 찾을 수 없습니다.\n", name);
}
void modify(std::list<node>* iList, char* name)
{
	int num;
	char modifystring[20];
	node head;
	std::list<node>::iterator findIter = Search(iList, name);
	if (findIter != iList->end())
	{
		while (TRUE)
		{
			system("cls");
			printf("학생 정보 검색 완료\n");
			ShowStudent(findIter);
			printf("\n\n");
			printf("수정할 항목을 선택하시오\n");
			printf("1.이름  2.나이  3.주소  4.점수  5.수정종료\n");
			scanf("%d", &num);
			switch (num)
			{
			case 1:
				printf("현재이름 : %s\n", findIter->name);
				strcpy(modifystring, findIter->name);
				printf("수정할 이름 : ");
				scanf("%s", findIter->name);
				printf("%s -> %s 로 이름 수정 완료\n", modifystring, findIter->name);
				break;
			case 2:
				printf("현재 나이 : %d\n", findIter->age);
				num = findIter->age;
				printf("수정할 나이 : ");
				scanf("%d", &findIter->age);
				printf("%d -> %d 로 이름 수정 완료\n", num, findIter->age);
				break;
			case 3:
				printf("현재 주소 : %s\n", findIter->add);
				strcpy(modifystring, findIter->add);
				printf("수정할 주소 : ");
				scanf("%s", findIter->add);
				printf("%s -> %s 로 주소 수정 완료\n", modifystring, findIter->add);
				break;
			case 4:
				printf("현재 점수\n");
				printf("국어 : %d\t영어 : %d\t수학 : %d\n", findIter->kor, findIter->eng, findIter->mat);
				printf("수정할 국어 점수 : ");
				scanf("%d", head.kor);
				findIter->kor = head.kor;
				printf("수정할 영어 점수 : ");
				scanf("%d", head.eng);
				findIter->eng = head.eng;
				printf("수정할 수학 점수 : ");
				scanf("%d", head.mat);
				findIter->mat = head.mat;
				SetGrade(&head);

				printf("점수 수정 완료\n");
				break;
			case 5:
				printf("수정을 종료합니다\n");
				return;
			}
		}
	}
	else
		printf("%s 찾을 수 없습니다.\n", name);
}

void DeleteData(std::list<node>* iList, char* name)
{
	std::list<node>::iterator findIter = Search(iList, name);
	if (findIter != iList->end())
		iList->erase(findIter);

	else
		printf("Data %d Not Found!\n", name);
}
void Release(std::list<node>* iList)
{
	while (!iList->empty())
	{
		iList->pop_back();
	}
}

void main()
{
	std::list<node> iList;
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
			iList.push_back(create());
			printf("학생 정보 입력 완료\n");
			system("pause");
			break;
		case 2:
			printf("학생 이름 입력 : ");
			scanf("%s", name);
			SearchData(&iList, name);
			system("pause");
			break;
		case 3:
			printf("%10s%10s%10s\n", "학생이름", "학생나이", "학생주소");
			PrintList(iList);
			system("pause");
			break;
		case 4:
			system("cls");
			printf("수정할 학생 이름 : ");
			scanf("%s", name);
			modify(&iList, name);
			break;

		case 5:
			printf("학생 이름 입력 : ");
			scanf("%s", name);
			DeleteData(&iList, name);
			break;
		case 6:
			Release(&iList);
			return;
		}
	}
}