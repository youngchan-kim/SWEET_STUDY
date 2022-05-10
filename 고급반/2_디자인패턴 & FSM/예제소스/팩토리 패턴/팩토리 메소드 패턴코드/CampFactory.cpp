#include "CampFactory.h"



CampFactory::CampFactory()
{
	m_pCharaceter = NULL;
}

Character* CampFactory::OrderCharacter(string name)
{
	CreateCharacter(name);
	if(m_pCharaceter != NULL)
	{
		m_pCharaceter->Make_Body();
		m_pCharaceter->Make_Arms();
		m_pCharaceter->Make_Legs();
		m_pCharaceter->Make_Face();
		m_pCharaceter->Make_Trait();
	}
	return m_pCharaceter;
}

CampFactory::~CampFactory()
{
}

HordeCamp* HordeCamp::m_hThis = NULL;
void HordeCamp::CreateCharacter(string name)
{
	if (name == "��ũ")
		m_pCharaceter = new Orc;
	else if (name == "�𵥵�")
		m_pCharaceter = new Undead;
	else if (name == "Ÿ�췻")
		m_pCharaceter = new Tauren;
	else if (name == "Ʈ��")
		m_pCharaceter = new Troll;
	else if (name == "���忤��")
		m_pCharaceter = new Blood_Elf;
	else if (name == "���")
		m_pCharaceter = new Goblin;
	else if (name == "�Ǵٷ�")
		m_pCharaceter = new Pandaren;
	else
		cout << "�ش� ������ �����ϴ�.";
	m_pCharaceter->SetName(name,"ȣ��");
}

AllianceCamp* AllianceCamp::m_hThis = NULL;
void AllianceCamp::CreateCharacter(string name)
{
	if (name == "�ΰ�")
		m_pCharaceter = new Human;
	else if (name == "�����")
		m_pCharaceter = new Dwarf;
	else if (name == "����Ʈ����")
		m_pCharaceter = new Night_Elf;
	else if (name == "���")
		m_pCharaceter = new Gnome;
	else if (name == "�巹����")
		m_pCharaceter = new Draenei;
	else if (name == "�����ΰ�")
		m_pCharaceter = new Worgen;
	else if (name == "�Ǵٷ�")
		m_pCharaceter = new Pandaren;
	else
	{
		m_pCharaceter = NULL;
		cout << "�ش� ������ �����ϴ�.";
	}
	if(m_pCharaceter != NULL)
		m_pCharaceter->SetName(name, "����̾�");
}
