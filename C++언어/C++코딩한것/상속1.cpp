#include<iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A Class ����" << endl;
	}
};

class B : public A //A�� �θ� �ǰ� B�� �ڽ��� �ȴ�.
{
public:
	B()
	{
		cout << "B Class ����" << endl;
	}
};

void main()
{
	B b;// A���� ���� ����
}