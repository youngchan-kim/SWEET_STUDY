#include<iostream>
using namespace std;

class A
{
public:
	void func1()
	{
		cout << "A �Լ� �Դϴ�." << endl;
	}
};

class B
{
public:
	void func2()
	{
		cout << "B �Լ� �Դϴ�." << endl;
	}
};
class C : public A, public B
{
public:
	void func3()
	{
		func1();
		func2();
	}
};
void main()
{
	C c;
	c.func3();
}