#include "circle.h"



circle::circle()
{
}

void circle::Draw()
{
	cout << fixed << setprecision(4) << "������ : " << pi << " �� ������ �׷Ƚ��ϴ�." << endl;
}

void circle::SetSize()
{
	cout << "������ : ";
	cin >> pi;
}

circle::~circle()
{
}
