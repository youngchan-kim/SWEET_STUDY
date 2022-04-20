#include <iostream>

using namespace std;

class A
{
private:
	int x, y;
public:
	friend void Setxy(A& a);
	A() { x = 0; y = 0; }
	void Showxy()
	{
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}
};

void Setxy(A& a)
{
	cout << "x,yÁÂÇ¥ ÀÔ·Â : " << endl;
	cin >> a.x >> a.y;
}

void main()
{
	A a;
	a.Showxy();
	Setxy(a);
	a.Showxy();
}