#include "Field.h"



Field::Field()
{
}
Field::~Field()
{
}



void BeachField::SetField() 
{
	type = "�غ����� �ʵ�";
}
BeachField::BeachField()
{
	SetField();
	cout << "�غ����� �ʵ� ���� �Ϸ�" << endl;
}
BeachField::~BeachField()
{
}



void VolcanoField::SetField()
{
	type = "ȭ������ �ʵ�";
}
VolcanoField::VolcanoField()
{
	SetField();
	cout << "ȭ������ �ʵ� ���� �Ϸ�" << endl;
}
VolcanoField::~VolcanoField()
{
}