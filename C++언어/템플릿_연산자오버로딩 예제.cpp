#include<iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int Num1, int Num2)
	{
		x = Num1;
		y = Num2;
	}
	void Show()
	{
		cout << "x = " << this->x << endl;
		cout << "y = " << this->y << endl;
	}
	friend bool operator < (Point P1, Point P2);
};

bool operator < (Point P1, Point P2)
{
	if (P1.x < P2.x)
		return true;
	else if (P1.x == P2.x)
	{
		if (P1.y < P2.y)
			return true;
		else return false;
	}
	else if (P1.x > P1.x)
		return false;
}

template <typename t1>
t1 Little(t1 P1, t1 P2)
{
	if (P1 < P2)
		return P1;
	else
		return P2;
}

void main()
{
	int Num1 = 10, Num2 = 20;
	float fNum1 = 10.1, fNum2 = 10.2;
	char ch1 = 'a', ch2 = 'b';
	Point P1(10, 10), P2(20, 20);
	Little(P1, P2).Show();
}