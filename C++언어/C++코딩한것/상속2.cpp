#include<iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A Class ������ ȣ��" << endl;
	}
	~A()
	{
		cout << "A Class �Ҹ��� ȣ��" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B Class ������ ȣ��" << endl;
	}
	~B()
	{
		cout << "B Class �Ҹ��� ȣ��" << endl;
	}
};

void main()
{
	B b;
}