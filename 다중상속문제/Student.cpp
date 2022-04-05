#include "Student.h"

Student::Student() {}

void Student::Input()
{
	School::Information();
	Person::Information();
	system("cls");
}

void Student::Output()
{
	School::Print();
	Person::Print();
	system("pause");
}

Student::~Student() {}