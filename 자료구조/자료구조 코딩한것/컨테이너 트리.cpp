#include<map>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
//Ʈ���� ��� ���踦 ���� ���ϴ� �����͸� ã�� ���
// key���� ����

struct Student
{
	char Name[256];
	int Age;
	int Class;
};

char* CreatName()
{
	switch (rand() % 5)
	{
	case 0:
		return (char*)"�����";
	case 1:
		return (char*)"�ڼ���";
	case 2:
		return (char*)"������";
	case 3:
		return (char*)"������";
	case 4:
		return (char*)"������";
	default:
		return (char*)"ȫ�浿";
	}
}

Student CreateStudent()
{
	Student st;
	strcpy(st.Name, CreatName());
	st.Class = rand() % 4 + 1;
	st.Age = rand() % 4 + 20;
	return st;

}

void PrintStudentMap(std::map<int, Student> StudentMap)
{
	for (std::map<int, Student>::iterator iter = StudentMap.begin(); iter != StudentMap.end(); iter++)
	{
		printf("%s(%d) : %d��\t%d�г�\n", iter->second.Name, iter->first, iter->second.Age, iter->second.Class);
		printf("\n");
	}
	printf("-----------------------\n");
}

void main()
{
	srand(time(NULL));
	int StudentNumber = 20220001;
	std::map<int, Student> StudentMap;

	//Ʈ���� ���� Ű���� ������ �ȵȴ�.
	for (int i = 0; i < 10; i++)
		StudentMap[StudentNumber++] = CreateStudent();//�� ����� 

	StudentMap.insert(std::make_pair(StudentNumber++, CreateStudent()));
	PrintStudentMap(StudentMap);

	StudentMap[20220001] = CreateStudent();//�� ����� ������ �ȴ�.
	PrintStudentMap(StudentMap);
	
	StudentMap.insert(std::make_pair(20220001, CreateStudent()));// �̹���� ������ �ȵȴ�.
	PrintStudentMap(StudentMap);
	
	StudentMap.at(20220001);
	StudentMap[20220001];
	StudentMap.find(20220001);
}