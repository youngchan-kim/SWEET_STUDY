#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//���� �θ� Class
class Character
{
protected:
	string m_szname;
	string m_szCampName;
	vector<string> vec_Trait;
public:
	virtual void Make_Body() = 0;
	virtual void Make_Arms() = 0;
	virtual void Make_Legs() = 0;
	virtual void Make_Face() = 0;
	virtual void Make_Trait() = 0;
	inline void SetName(string name,string name2)
	{
		this->m_szname = name;
		this->m_szCampName = name2;
	}	
	inline string GetName()
	{
		return m_szname;
	}
	inline string GetCampName()
	{
		return m_szCampName;
	}
	Character();
	~Character();
};
//�ΰ�����
class Human : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//����� ����
class Dwarf : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//����Ʈ���� ����
class Night_Elf : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//��� ����
class Gnome : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//�巹���� ����
class Draenei : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//�����ΰ� ����
class Worgen : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//�Ǵٷ� ����
class Pandaren : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//��ũ ����
class Orc : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//�𵥵� ����
class Undead : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//Ÿ�췻 ����
class Tauren : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//Ʈ�� ����
class Troll : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//���忤�� ����
class Blood_Elf : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//��� ����
class Goblin : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
