#include "Triangle.h"



Triangle::Triangle()
{
}

void Triangle::Draw()
{
	cout << "�غ� : " << x << " ���� : " << y << " �� �ﰢ���� �׷Ƚ��ϴ�." << endl;
}

void Triangle::SetSize()
{
	cout << "�غ� : ";
	cin >> x;
	cout << "���� : ";
	cin >> y;
}

Triangle::~Triangle()
{
}
