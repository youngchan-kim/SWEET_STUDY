#include <iostream>
#include <string>
using namespace std;

enum GENDER
{
	GENDER_MAN,
	GENDER_WOMAN
};

class Person
{
private:
	string Name;
	int Age;
	GENDER Gender;
public:
	void SetName(string _Name, int _Age, GENDER _Gender);
	string GetName();
	void ShowPerson();
};

void Person:: SetName(string _Name, int _Age, GENDER _Gender)
{
	Name = _Name;
	Age = _Age;
	Gender = _Gender;
}
string Person::GetName()
{
	return Name;
}
void Person::ShowPerson()
{
	cout << "�̸� : " << Name << endl;
	cout << "���� : " << Age << endl;
	cout << "���� : ";
	switch (Gender)
	{
	case GENDER_MAN:
		cout << "����" << endl;
		break;
	case GENDER_WOMAN:
		cout << "����" << endl;
		break;
	}
}
void main()
{
	Person P1;
	P1.SetName("������", 25, GENDER_WOMAN);
	cout << "======" << P1.GetName() << "�� ����" << "======" << endl;
	P1.ShowPerson();
}