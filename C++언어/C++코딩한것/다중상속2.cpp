#include<iostream>
using namespace std;

class A
{
public:
	void func()
	{
		cout << "A �Լ� �Դϴ�." << endl;
	}
};

class B
{
public:
	void func()
	{
		cout << "B �Լ� �Դϴ�." << endl;
	}
};
class C : public A, public B
{
public:
	void func3()
	{
		func();
		func();
	}//����
};
void main()
{
	C c;
	c.func3();
}