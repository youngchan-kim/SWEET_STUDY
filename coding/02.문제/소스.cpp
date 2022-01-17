#include <iostream>
#include<Windows.h>
using namespace std;

#define STUDENTMAX 10
#define GRADEMAX 5
#define TRUE 1
#define FIRSTCLASS 1
#define THIRDCLASS 3

typedef struct Student
{
	string name;
	int age;
	int clas;
	int num;
	int kor;
	int eng;
	int math;
	int sum;
	int avg;
	string grade;
}Student;

Student Grade(Student* student[], int StudentCount)
{
	student[StudentCount]->sum = student[StudentCount]->kor + student[StudentCount]->eng + student[StudentCount]->math;
	student[StudentCount]->avg = student[StudentCount]->sum / 3;
	if(student[StudentCount]->avg >= 90)
		student[StudentCount]->grade = 'A';
	else if(student[StudentCount]->avg < 90 && student[StudentCount]->avg >= 80)
		student[StudentCount]->grade = 'B';
	else if (student[StudentCount]->avg < 80 && student[StudentCount]->avg >= 70)
		student[StudentCount]->grade = 'C';
	else if (student[StudentCount]->avg < 70 && student[StudentCount]->avg >= 60)
		student[StudentCount]->grade = 'D';
	else if (student[StudentCount]->avg < 60 )
		student[StudentCount]->grade = 'F';

	return *student[StudentCount];
}

Student Input(Student* student[], int StudentCount)
{
	int tmpgrace;
	student[StudentCount] = new Student;

	system("cls");
	cout << "\t======"<< StudentCount <<"번째 학생======" << endl;
	cout << "\t이름 : ";
	cin >> student[StudentCount]->name;
	cout << "\t나이 : ";
	cin >> student[StudentCount]->age;
	while (TRUE)
	{
		cout << "\t학년(1~3) : ";
		cin >> tmpgrace;
		if (FIRSTCLASS<= tmpgrace && tmpgrace <= THIRDCLASS)
		{
			student[StudentCount]->clas = tmpgrace;
			break;
		}
		else
			cout << "잘못 입력 다시" << endl;
	}
	cout << "\t국어 점수 : ";
	cin >> student[StudentCount]->kor;
	cout << "\t영어 점수 : ";
	cin >> student[StudentCount]->eng;
	cout << "\t수학 점수 : ";
	cin >> student[StudentCount]->math;
	Grade(student, StudentCount);
	return *student[StudentCount];
}

void Printf(Student* student[], int i)
{
	cout << "======" << i << "번째 학생 ======" << endl;
	cout << "이름 : " << student[i]->name << endl;
	cout << "나이 : " << student[i]->age << endl;
	cout << "학년 : " << student[i]->clas << "학년" << endl;
	cout << "국어점수 : " << student[i]->kor << endl;
	cout << "영어점수 : " << student[i]->eng << endl;
	cout << "수학점수 : " << student[i]->math << endl;
	cout << "합계 점수 : " << student[i]->sum;
	cout << "\t평균 점수 : " << student[i]->avg << endl;
	cout << "등급 : [" << student[i]->grade << "]" << endl << endl;
}

void NameSerch(Student* student[], int StudentCount)
{
	string name;
	bool check = false;
	cout << "이름 입력 : ";
	cin >> name;
	for (int i = 0; i < StudentCount; i++)
	{
		if (name == student[i]->name)
		{
			Printf(student, i);
			check = true;
		}
	}
	if (check == false)
		cout << "찾는 학생이 없습니다." << endl;
}

void GradeSerch(Student* student[], int StudentCount)
{
	string gradename[GRADEMAX] = {"A", "B", "C", "D", "F"};
	for (int i = 0; i < GRADEMAX; i++)
	{
		cout << "┌─────────" << gradename[i] << "등급─────────┐" << endl;
		for (int j = 0; j < StudentCount; j++)
		{
			if(gradename[i]== student[j]->grade)
				Printf(student, j);
		}
		cout << "└─────────────────────┘" << endl;
	}
}

void ClasSerch(Student* student[], int StudentCount)
{
	for (int i = 1; i <= THIRDCLASS; i++)
	{
		cout << "┌─────────" << i << "학년─────────┐" << endl;
		for (int j = 0; j < StudentCount; j++)
		{
			if (i == student[j]->clas)
				Printf(student, j);
		}
		cout << "└─────────────────────┘" << endl;
	}
}

void main()
{
	int Select, StudentCount = 0;
	Student* student[STUDENTMAX];
	
	while (TRUE)
	{
		system("cls");
		cout << "\t===학생정보관리=== (학생수 : " << StudentCount << "명)" << endl;
		cout << "\t1.학생등록" << endl;
		cout << "\t2.학생정보 보기" << endl;
		cout << "\t3.학생 검색" << endl;
		cout << "\t4.등급별 보기" << endl;
		cout << "\t5.학년별 보기" << endl;
		cout << "\t6.종료" << endl;
		cout << "\t입력 : ";
		cin >> Select;
		switch (Select)
		{
		case 1:
			if (StudentCount < STUDENTMAX)
			{
				Input(student, StudentCount);
				StudentCount++;
			}
			system("pause");
			break;
		case 2:
			system("cls");
			for (int i = 0; i < StudentCount; i++)
				Printf(student, i);
			system("pause");
			break;
		case 3:
			system("cls");
			NameSerch(student, StudentCount);
			system("pause");
			break;
		case 4:
			system("cls");
			GradeSerch(student, StudentCount);
			system("pause");
			break;
		case 5:
			system("cls");
			ClasSerch(student, StudentCount);
			system("pause");
			break;
		case 6:
			for (int i = 0; i < StudentCount; i++)
			{
				cout << i + 1 << "번 학생 : " << student[i] << endl;
				delete student[i];
				cout << "할당 해제 완료" << endl;
			}
			system("pause");
			return;
		}
	}
}