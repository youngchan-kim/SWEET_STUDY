#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A�Լ� ������." << endl;
	}
};
class B : public A
{
public:
	B()
	{
		cout << "B�Լ� ������." << endl;
	}
};
class C : public A
{
public:
	C()
	{
		cout << "C�Լ� ������." << endl;
	}
};
class D : public B, public C
{
public:
	D()
	{
		cout << "D�Լ� ������." << endl;
	}
};

void main()
{
	D d;
}


