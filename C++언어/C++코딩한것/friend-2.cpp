#include <iostream>

using namespace std;

class A
{
private:
	int x, y;
public:
	friend class B;
	A(int a, int b) : x(a), y(b) {}


	void Showxy()
	{
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}
};

class B
{
private:
	int x, y;
public:
	B() :x(0), y(0) {}
	void GetA(A& a)
	{
		x = a.x; y = a.y;
	}

	void Showxy()
	{
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}
};

void main()
{
	A a(10, 15);
	B b;
	a.Showxy();
	b.Showxy();
	b.GetA(a);
	a.Showxy();
	b.Showxy();
}