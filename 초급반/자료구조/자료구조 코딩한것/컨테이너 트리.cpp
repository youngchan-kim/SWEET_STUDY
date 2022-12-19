#include<map>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
//트리는 대소 관계를 통해 원하는 데이터를 찾는 방법
// key값은 유일

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
		return (char*)"김민지";
	case 1:
		return (char*)"박성우";
	case 2:
		return (char*)"배현서";
	case 3:
		return (char*)"민정우";
	case 4:
		return (char*)"최은지";
	default:
		return (char*)"홍길동";
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
		printf("%s(%d) : %d살\t%d학년\n", iter->second.Name, iter->first, iter->second.Age, iter->second.Class);
		printf("\n");
	}
	printf("-----------------------\n");
}

void main()
{
	srand(time(NULL));
	int StudentNumber = 20220001;
	std::map<int, Student> StudentMap;

	//트리는 같은 키값은 저장이 안된다.
	for (int i = 0; i < 10; i++)
		StudentMap[StudentNumber++] = CreateStudent();//이 방식은 

	StudentMap.insert(std::make_pair(StudentNumber++, CreateStudent()));
	PrintStudentMap(StudentMap);

	StudentMap[20220001] = CreateStudent();//이 방식은 수정이 된다.
	PrintStudentMap(StudentMap);
	
	StudentMap.insert(std::make_pair(20220001, CreateStudent()));// 이방식은 수정이 안된다.
	PrintStudentMap(StudentMap);
	
	StudentMap.at(20220001);
	StudentMap[20220001];
	StudentMap.find(20220001);
}