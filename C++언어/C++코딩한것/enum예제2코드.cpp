#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;

#define WEAPONMAX 5

enum WEAPON
{
	WEAPON_START,
	WEAPON_DAGGER = 0,
	WEAPON_GUN,
	WEAPON_SWORD,
	WEAPON_WAND,
	WEAPON_BOW,
	WEAPON_HAMMER,
	WEAPON_END
};

struct Weapon
{
	WEAPON WeaponType;
	string Name;
	int Damage;
	int Reach;
	int Speed;
};

void ShowWeapon(Weapon w)
{
	cout << "〓〓〓" << w.Name << "〓〓〓" << endl;
	cout << "공격력 : " << w.Damage << "  사정거리 : " << w.Reach << "m" << endl;
	cout << "공격속도 : 분당 " << w.Speed << "회 공격" << endl << endl;
}

void ShowWeaponList(Weapon* WeaponList, WEAPON p)
{
	cout << "==========";
	switch (WEAPON)
	{
	case WEAPON_DAGGER:
		cout << "Dagger";	
		break;
	case WEAPON_GUN:
		cout << "Gun";
		break;
	case WEAPON_SWORD:
		cout << "Sword";
		break;
	case WEAPON_WAND:
		cout << "Wand";
		break;		
	case WEAPON_BOW:
		cout << "Bow";
		break;
	case WEAPON_HAMMER:
		cout << "Hammer";
		break;
	case WEAPON_END:
		break;
	default:
		break;
	}
	cout << "==========" << endl << endl;
	for (int i = 0; i < WEAPONMAX; i++)
	{
		if (WeaponList[i].WeaponType == p)
			ShowWeapon(WeaponList[i]);
	}
	cout << endl << "==============================" << endl << endl;
}

void main()
{
	Weapon WeaponList[WEAPONMAX] = {{WEAPON_SWORD, "그레이트 소드" ,500, 5, 10},
		{WEAPON_BOW,"라이트 보우", 50, 300, 60},
		{WEAPON_BOW,"라이트 보우", 100, 400, 30},
		{WEAPON_GUN, "리볼버", 50, 700, 30},
		{WEAPON_SWORD, "에고 소드", 2000, 4, 20}};
	for (int i = WEAPON_START; i < WEAPON_END; i++)
		ShowWeaponList(WeaponList, (WEAPON)i);
}