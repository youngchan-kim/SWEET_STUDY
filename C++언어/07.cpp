#include<iostream>
using namespace std;

class person
{
private:
	int m_iAge;
	string m_strName;
public:
	person(int _age, string tmp)
	{
		m_iAge = _age;
		m_strName = tmp;
	}
	person(person* tmp)//���� ������
	{
		m_iAge = tmp->m_iAge;
		m_strName = tmp->m_strName;
	}
	void print()
	{
		cout << "���� : " << m_iAge << endl;
		cout << "�̸� : " << m_strName << endl;
	}
};

void main()
{
	person p1(26, "����ȣ");
	person p2(&p1);
	p1.print();
	p2.print();
}