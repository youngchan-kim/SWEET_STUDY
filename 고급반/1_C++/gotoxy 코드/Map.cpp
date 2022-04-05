#include "Map.h"



Map::Map()
{
	cout << "�� X �Է� :";
	cin >> m_ix;
	cout << "�� y �Է� :";
	cin >> m_iy;
	cout << "�� ���� ���� �Է� :";
	cin >> m_iWidth;
	cout << "�� ���� ���� �Է� :";
	cin >> m_iHeight;
	m_Character = new Character((m_ix + m_iWidth)* 0.5f, m_iy + (m_iHeight * 0.5f));
}


void Map::MapDraw()
{
	m_DrawManager.BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
	m_Character->Draw();
	m_Character->Move(m_ix,m_iy,m_iWidth,m_iHeight);
}

Map::~Map()
{
	delete m_Character;
}
