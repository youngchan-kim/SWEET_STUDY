#include "School.h"


School::School() {}

void School::Information()
{
	cout << "�г� �Է� : ";
	cin >> i_mgrade;
	cout << "�� �Է� : ";
	cin >> i_mclass;
	cout << "�л� ��ȣ �Է� : ";
	cin >> i_mnumber;
}

void School::Print()
{
	cout << i_mgrade << " �г� " << i_mclass << " �� " << i_mnumber << " �� �л�" << endl;
}

School::~School() {}


