#include "Person.h"

Person::Person() {}

void Person::Information()
{

	cout << "나이 입력 : ";
	cin >> i_mage;
	cout << "이름 입력 : ";
	cin >> str_mname;
	cout << "성별 입력 : ";
	cin >> str_mgender;
}

void Person::Print()
{
	cout << "나이 : " << i_mage << endl << "이름 : " << str_mname << endl << "성별 : " << str_mgender << endl;
}

Person::~Person() {}