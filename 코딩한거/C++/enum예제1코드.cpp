#include <iostream>
#include <Windows.h>
using namespace std;

enum PLAYER
{
	PLAYER_START = 1,
	PLAYER_ARCHER = PLAYER_START,
	PLAYER_MAGICIAN,
	PLAYER_WARRIOR,
	PLAYER_END = PLAYER_WARRIOR
};

enum PLAYPATTERN
{
	PLAYPATTERN_ATTACK=1,
	PLAYPATTERN_MOVE,
	PLAYPATTERN_DEFENCE
};

struct Player
{
	PLAYER PlayerType;
	int Damage;
	int Speed;
	int Defend;
};

void Attack(Player p)
{
	switch (p.PlayerType)
	{
	case PLAYER_ARCHER:
		cout << "궁수가 원거리에서 화살 공격!(데미지 : " << p.Damage << ")" << endl;
		break;

	case PLAYER_MAGICIAN:
		cout << "마법사가 원거리에서 마법 공격!(데미지 : " << p.Damage << ")" << endl;
		break;
	
	case PLAYER_WARRIOR:
		cout << "전사가 근거리에서 근접 공격!(데미지 : " << p.Damage << ")" << endl;
		break;
	}
}

void Defence(Player p)
{
	switch (p.PlayerType)
	{
	case PLAYER_ARCHER:
		cout << "궁수가 활집을 사용하여 방어(상쇄데미지 : " << p.Defend << ")" << endl;
		break;

	case PLAYER_MAGICIAN:
		cout << "마법사가 마법서를 사용하여 방어(상쇄데미지 : " << p.Defend << ")" << endl;
		break;

	case PLAYER_WARRIOR:
		cout << "전사가 방패를 사용하여 방어(상쇄데미지 : " << p.Defend << ")" << endl;
		break;
	}
}

void Move(Player p)
{
	switch (p.PlayerType)
	{
	case PLAYER_ARCHER:
		cout << "궁수가 점프하여 이동(이동속도 : " << p.Speed << ")" << endl;
		break;

	case PLAYER_MAGICIAN:
		cout << "마법사가 텔레포트하여 이동(이동속도 : " << p.Speed << ")" << endl;
		break;

	case PLAYER_WARRIOR:
		cout << "전사가 돌진하여 이동(이동속도 : " << p.Speed << ")" << endl;
		break;
	}
}
void main()
{
	Player player;
	int Choice;
	while (1)
	{
		system("cls");
		cout << "=====직업선택=====" << endl;
		cout << "1.궁수" << endl;
		cout << "2.마법사" << endl;
		cout << "3.전사" << endl;
		cout << "선택";
		cin >> Choice;
		if (Choice >= PLAYER_START && Choice <= PLAYER_END)
		{
			player.PlayerType = (PLAYER)Choice; 
			//형변환을 위해  (PLAYER)Choice;를 씀 이유는 enum이 int를 받는 형식인데
			//int는 여러가지 enum(의미)를 받을 수 있으므로 형변환이 꼭 필요하다.
			//int에 enum을 받을 수는 있다. 
			//enum이라는 의미를 int에 사용한것이므로 int에 enum은 사용이 가능하다
			break;
		}
		cout << "직업을 잘못 선택 하셧습니다." << endl;
		system("pause");
	}
	switch (player.PlayerType)
	{
	case PLAYER_ARCHER:
		player.Damage = 50;
		player.Defend = 10;
		player.Speed = 50;
		break;
	case PLAYER_MAGICIAN:
		player.Damage = 100;
		player.Defend = 5;
		player.Speed = 30;
		break;
	case PLAYER_WARRIOR:
		player.Damage = 30;
		player.Defend = 20;
		player.Speed = 20;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "=====행동 선택=====" << endl;
		cout << "1.공격" << endl;
		cout << "2.이동" << endl;
		cout << "3.방어" << endl;
		cout << "선택 : ";
		cin >> Choice;
		switch (Choice)
		{
		case PLAYPATTERN_ATTACK:
			Attack(player);
			break;
		case PLAYPATTERN_MOVE:
			Move(player);
			break;
		case PLAYPATTERN_DEFENCE:
			Defence(player);
			break;
		default:
			cout << "잘못 선택 하셧습니다." << endl;
			break;
		}
		system("pause");
	}
}


