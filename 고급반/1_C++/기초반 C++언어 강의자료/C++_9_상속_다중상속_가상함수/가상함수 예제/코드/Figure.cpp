#include "Figure.h"



Figure::Figure()
{
}

void Figure::Draw()
{
	cout << "���� : " << x << " ���� : " << y << " �� ������ �׷Ƚ��ϴ�." << endl;
	return;
}

void Figure::SetSize()
{
	cout << "���� : ";
	cin >> x;
	cout << "���� : ";
	cin >> y;
}

Figure::~Figure()
{
}
