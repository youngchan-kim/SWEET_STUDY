#include "School.h"


School::School() {}

void School::Information()
{
	cout << "학년 입력 : ";
	cin >> i_mgrade;
	cout << "반 입력 : ";
	cin >> i_mclass;
	cout << "학생 번호 입력 : ";
	cin >> i_mnumber;
}

void School::Print()
{
	cout << i_mgrade << " 학년 " << i_mclass << " 반 " << i_mnumber << " 번 학생" << endl;
}

School::~School() {}


