#include <iostream>

using namespace std;

class A
{
private:
	int x, y;
public:
	A(int a, int b) : x(a), y(b) {}
	friend void Showxy(A& a)
	{
		cout << "x = " << a.x << endl;
		cout << "y = " << a.y << endl;
	}
};

void main()
{
	A a(10, 15);
	Showxy(a);

}