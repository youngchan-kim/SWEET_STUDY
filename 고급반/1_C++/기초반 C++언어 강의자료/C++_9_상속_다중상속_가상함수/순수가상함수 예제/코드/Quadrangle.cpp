#include "Quadrangle.h"



Quadrangle::Quadrangle()
{
}



void Quadrangle::Draw()
{
	cout << "���� : " << x << " ���� : " << y << " �� �簢���� �׷Ƚ��ϴ�." << endl;
}

void Quadrangle::SetSize()
{
	cout << "���� : ";
	cin >> x;
	cout << "���� : ";
	cin >> y;
}


Quadrangle::~Quadrangle()
{
}
