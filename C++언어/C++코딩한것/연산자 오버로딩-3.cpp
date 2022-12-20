#include <iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int a, int b) { x = a; y = b; }
	void Print() { cout << "x = " << x << ", y = " << y << "\n";}
	bool operator==(Point tmp);
};

bool Point::operator==(Point tmp)
{
	if ((this->x == tmp.x) && (this->y == tmp.y))
		return true;
	else
		return false;
}

void main()
{
	Point ov1(10, 20), ov2(10, 20);
	if (ov1 == ov2)
		cout << "°°´Ù." << "\n";
}