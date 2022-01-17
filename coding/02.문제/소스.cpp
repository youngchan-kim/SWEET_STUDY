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
	cout << "\t======"<< StudentCount <<"��° �л�======" << endl;
	cout << "\t�̸� : ";
	cin >> student[StudentCount]->name;
	cout << "\t���� : ";
	cin >> student[StudentCount]->age;
	while (TRUE)
	{
		cout << "\t�г�(1~3) : ";
		cin >> tmpgrace;
		if (FIRSTCLASS<= tmpgrace && tmpgrace <= THIRDCLASS)
		{
			student[StudentCount]->clas = tmpgrace;
			break;
		}
		else
			cout << "�߸� �Է� �ٽ�" << endl;
	}
	cout << "\t���� ���� : ";
	cin >> student[StudentCount]->kor;
	cout << "\t���� ���� : ";
	cin >> student[StudentCount]->eng;
	cout << "\t���� ���� : ";
	cin >> student[StudentCount]->math;
	Grade(student, StudentCount);
	return *student[StudentCount];
}

void Printf(Student* student[], int i)
{
	cout << "======" << i << "��° �л� ======" << endl;
	cout << "�̸� : " << student[i]->name << endl;
	cout << "���� : " << student[i]->age << endl;
	cout << "�г� : " << student[i]->clas << "�г�" << endl;
	cout << "�������� : " << student[i]->kor << endl;
	cout << "�������� : " << student[i]->eng << endl;
	cout << "�������� : " << student[i]->math << endl;
	cout << "�հ� ���� : " << student[i]->sum;
	cout << "\t��� ���� : " << student[i]->avg << endl;
	cout << "��� : [" << student[i]->grade << "]" << endl << endl;
}

void NameSerch(Student* student[], int StudentCount)
{
	string name;
	bool check = false;
	cout << "�̸� �Է� : ";
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
		cout << "ã�� �л��� �����ϴ�." << endl;
}

void GradeSerch(Student* student[], int StudentCount)
{
	string gradename[GRADEMAX] = {"A", "B", "C", "D", "F"};
	for (int i = 0; i < GRADEMAX; i++)
	{
		cout << "��������������������" << gradename[i] << "��ަ�������������������" << endl;
		for (int j = 0; j < StudentCount; j++)
		{
			if(gradename[i]== student[j]->grade)
				Printf(student, j);
		}
		cout << "����������������������������������������������" << endl;
	}
}

void ClasSerch(Student* student[], int StudentCount)
{
	for (int i = 1; i <= THIRDCLASS; i++)
	{
		cout << "��������������������" << i << "�г⦡������������������" << endl;
		for (int j = 0; j < StudentCount; j++)
		{
			if (i == student[j]->clas)
				Printf(student, j);
		}
		cout << "����������������������������������������������" << endl;
	}
}

void main()
{
	int Select, StudentCount = 0;
	Student* student[STUDENTMAX];
	
	while (TRUE)
	{
		system("cls");
		cout << "\t===�л���������=== (�л��� : " << StudentCount << "��)" << endl;
		cout << "\t1.�л����" << endl;
		cout << "\t2.�л����� ����" << endl;
		cout << "\t3.�л� �˻�" << endl;
		cout << "\t4.��޺� ����" << endl;
		cout << "\t5.�г⺰ ����" << endl;
		cout << "\t6.����" << endl;
		cout << "\t�Է� : ";
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
				cout << i + 1 << "�� �л� : " << student[i] << endl;
				delete student[i];
				cout << "�Ҵ� ���� �Ϸ�" << endl;
			}
			system("pause");
			return;
		}
	}
}