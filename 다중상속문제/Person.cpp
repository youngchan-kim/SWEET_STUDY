#include "Person.h"

Person::Person() {}

void Person::Information()
{

	cout << "���� �Է� : ";
	cin >> i_mage;
	cout << "�̸� �Է� : ";
	cin >> str_mname;
	cout << "���� �Է� : ";
	cin >> str_mgender;
}

void Person::Print()
{
	cout << "���� : " << i_mage << endl << "�̸� : " << str_mname << endl << "���� : " << str_mgender << endl;
}

Person::~Person() {}