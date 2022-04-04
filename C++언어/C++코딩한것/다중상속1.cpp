#include<iostream>
using namespace std;

class A
{
public:
	void func1()
	{
		cout << "A 함수 입니다." << endl;
	}
};

class B
{
public:
	void func2()
	{
		cout << "B 함수 입니다." << endl;
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