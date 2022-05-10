#include"MapManager.h"
#include"Factory.h"
#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include<crtdbg.h>
using namespace std;

void menu()
{
	cout << "======Map Create======" << endl;
	cout << "   1.�� ����� " << endl;
	cout << "   2.�� ���" << endl;
	cout << "   3.����" << endl;
	cout << "======================" << endl;
}
void MapMenu()
{
	cout << "======Map List======" << endl;
	cout << "  1.ȭ�� ��" << endl;
	cout << "  2.�غ� ��" << endl;
	cout << "  3.���ư���" << endl;
	cout << "===================" << endl;
}

void main()
{
	_CrtSetDbgFlag( _CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF );
	//_crtBreakAlloc = 197;
	int choice;
	VolcanoFactory vf;
	BeachFactory bf;
	system("pause");
	while (1)
	{
		system("cls");
		menu();
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			MapMenu();
			cin >> choice;
			if (choice == 1)
				MapManager::GetInstans()->CreateMap(vf);
			else if (choice == 2)
				MapManager::GetInstans()->CreateMap(bf);
			else if (choice == 3)
				continue;
			else
				cout << "�߸� �Է� �ϼ˽��ϴ�." << endl;
		}
		else if (choice == 2)
		{
			MapManager::GetInstans()->ShowMapList();
		}
		else if (choice == 3)
		{
			MapManager::GetInstans()->Release();
			exit(1);
		}
		system("pause");
	}
}