#include<iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A 함수 생성자" << endl;
	}
};

class B:public A
{
public:
	B()
	{
		cout << "B 함수 생성자" << endl;
	}
};
class C : public A
{
public:
	C()
	{
		cout << "C 함수 생성자" << endl;
	}
};
class D : public B, public C
{
public:
	D()
	{
		cout << "D 함수 생성자" << endl;
	}
};
void main()
{
	D d;
}