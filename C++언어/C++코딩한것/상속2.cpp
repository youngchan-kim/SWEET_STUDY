#include<iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A Class 생성자 호출" << endl;
	}
	~A()
	{
		cout << "A Class 소멸자 호출" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B Class 생성자 호출" << endl;
	}
	~B()
	{
		cout << "B Class 소멸자 호출" << endl;
	}
};

void main()
{
	B b;
}