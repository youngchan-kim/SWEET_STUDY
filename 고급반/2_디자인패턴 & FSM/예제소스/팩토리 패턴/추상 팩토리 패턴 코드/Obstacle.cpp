#include "Obstacle.h"



Obstacle::Obstacle()
{
}
Obstacle::~Obstacle()
{
}



void BeachObstacle::SetObstacle()
{
	type = "�غ����� ��ֹ�";
}
BeachObstacle::BeachObstacle()
{
	SetObstacle();
	cout << "�غ����� ��ֹ� ���� �Ϸ�" << endl;
}
BeachObstacle::~BeachObstacle()
{
}



void VolcanoObstacle::SetObstacle()
{
	type = "ȭ������ ��ֹ�";
}
VolcanoObstacle::VolcanoObstacle()
{
	SetObstacle();
	cout << "ȭ����ֹ� ���� �Ϸ�" << endl;
}
VolcanoObstacle::~VolcanoObstacle()
{
}