#include <iostream>
using namespace std;

class Point
{
private:
	int m_ix;
	int m_iy;
public:
	Point() {}
	void SetNum(int x, int y)
	{
		m_ix = x;
		m_iy = y;
	}
	void ShowNum() const //뒤의 값이 상수화 된다. 대입 연산자를 못쓰게 막는다.
	{
		cout << "x = " << m_ix << endl;
		cout << "y = " << m_iy << endl;
		m_ix = 30;
		m_iy = 40;
		cout << "x= " << m_ix << endl;
	}
	int* GetNum()
	{
		return&m_ix;
	}
};

void main()
{
	Point p;
	p.SetNum(10, 20);
	p.ShowNum();
	*(p.GetNum()) = 100;
	p.ShowNum();
}