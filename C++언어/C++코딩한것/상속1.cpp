#include<iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A Class 생성" << endl;
	}
};

class B : public A //A가 부모가 되고 B가 자식이 된다.
{
public:
	B()
	{
		cout << "B Class 생성" << endl;
	}
};

void main()
{
	B b;// A까지 같이 실행
}