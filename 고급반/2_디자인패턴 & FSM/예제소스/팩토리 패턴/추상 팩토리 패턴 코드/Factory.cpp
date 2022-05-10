#include "Factory.h"



Factory::Factory()
{
}
Factory::~Factory()
{
}


Map* BeachFactory::MakeMap()
{
	Map* m = new Map("�غ�");
	cout << "�غ� �� ���� �Ϸ�" << endl;
	m->AddField(MakeField());
	m->AddObstacle(MakeObstacle());
	return m;
}
Field* BeachFactory::MakeField()
{
	return new BeachField;
}
Obstacle* BeachFactory::MakeObstacle()
{
	return new BeachObstacle;
}
BeachFactory::BeachFactory()
{
	cout << "�غ��� ���� ���� �Ϸ�" << endl;
}
BeachFactory::~BeachFactory()
{

}


Map* VolcanoFactory::MakeMap()
{
	Map* m = new Map("ȭ��");
	cout << "ȭ�� �� ���� �Ϸ�" << endl;
	m->AddField(MakeField());
	m->AddObstacle(MakeObstacle());
	return m;
}
Field* VolcanoFactory::MakeField()
{
	return new VolcanoField;
}
Obstacle* VolcanoFactory::MakeObstacle()
{
	return new VolcanoObstacle;
}
VolcanoFactory::VolcanoFactory()
{
	cout << "ȭ��� ���� ���� �Ϸ�" << endl;
}
VolcanoFactory::~VolcanoFactory()
{

}


