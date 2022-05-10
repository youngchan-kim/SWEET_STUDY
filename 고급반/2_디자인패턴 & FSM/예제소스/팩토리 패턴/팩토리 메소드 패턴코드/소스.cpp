#include<iostream>
#include<vector>
#include<Windows.h>
#include<crtdbg.h>
#include"Character.h"
#include"CampFactory.h"
using namespace std;
vector<Character*> vec_pCharacterList;
int Camp_Menu()
{
	system("cls");
	int choice;
	cout << "������������������������������������" << endl;
	cout << "��	�� ���� ��� ��		  ��" << endl;
	cout << "��	1.����̾� ����		  ��" << endl;
	cout << "��	2.ȣ�� ����		  ��" << endl;
	cout << "��	3.����			  ��" << endl;
	cout << "������������������������������������" << endl;
	cout << "	���� : ";
	cin >> choice;
	return choice;
}

void Horde_Menu()
{
	int choice;
	system("cls");
	cout << "��������������������������" << endl;
	cout << "��   �� ȣ�� ���� ��	��" << endl;
	cout << "��	1.��ũ		��" << endl;
	cout << "��	2.�𵥵�	��" << endl;
	cout << "��	3.Ÿ�췻	��" << endl;
	cout << "��	4.Ʈ��		��" << endl;
	cout << "��	5.���忤��	��" << endl;
	cout << "��	6.���	��" << endl;
	cout << "��	7.�Ǵٷ�	��" << endl;
	cout << "��������������������������" << endl;
	cout << "���� :";
	cin >> choice;
	switch (choice)
	{
	case 1:
		vec_pCharacterList.push_back(HordeCamp::GetInstans()->OrderCharacter("��ũ"));
		break;
	case 2:
		vec_pCharacterList.push_back(HordeCamp::GetInstans()->OrderCharacter("�𵥵�"));
		break;
	case 3:
		vec_pCharacterList.push_back(HordeCamp::GetInstans()->OrderCharacter("Ÿ�췻"));
		break;
	case 4:
		vec_pCharacterList.push_back(HordeCamp::GetInstans()->OrderCharacter("Ʈ��"));
		break;
	case 5:
		vec_pCharacterList.push_back(HordeCamp::GetInstans()->OrderCharacter("���忤��"));
		break;
	case 6:
		vec_pCharacterList.push_back(HordeCamp::GetInstans()->OrderCharacter("���"));
		break;
	case 7:
		vec_pCharacterList.push_back(HordeCamp::GetInstans()->OrderCharacter("�Ǵٷ�"));
		break;
	default:
		break;
	}
	system("pause");
}

void Alliance_Menu()
{
	Character* tmp;
	int choice;
	system("cls");
	cout << "����������������������������������" << endl;
	cout << "��     �� ����̾� ���� ��	��" << endl;
	cout << "��	1.�ΰ�			��" << endl;
	cout << "��	2.�����		��" << endl;
	cout << "��	3.����Ʈ����		��" << endl;
	cout << "��	4.���			��" << endl;
	cout << "��	5.�巹����		��" << endl;
	cout << "��	6.�����ΰ�		��" << endl;
	cout << "��	7.�Ǵٷ�		��" << endl;
	cout << "����������������������������������" << endl;
	cout << "���� :";
	cin >> choice;
	switch (choice)
	{
	case 1:
		tmp = AllianceCamp::GetInstans()->OrderCharacter("�ΰ�");
		if(tmp != NULL)
			vec_pCharacterList.push_back(tmp);
		break;
	case 2:
		vec_pCharacterList.push_back(AllianceCamp::GetInstans()->OrderCharacter("�����"));
		break;
	case 3:
		vec_pCharacterList.push_back(AllianceCamp::GetInstans()->OrderCharacter("����Ʈ����"));
		break;
	case 4:
		vec_pCharacterList.push_back(AllianceCamp::GetInstans()->OrderCharacter("���"));
		break;
	case 5:
		vec_pCharacterList.push_back(AllianceCamp::GetInstans()->OrderCharacter("�巹����"));
		break;
	case 6:
		vec_pCharacterList.push_back(AllianceCamp::GetInstans()->OrderCharacter("�����ΰ�"));
		break;
	case 7:
		vec_pCharacterList.push_back(AllianceCamp::GetInstans()->OrderCharacter("�Ǵٷ�"));
		break;
	default:
		break;
	}
	system("pause");
}


void main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 193;
	while (1)
	{
		switch (Camp_Menu())
		{
		case 1:
			Alliance_Menu();
			break;
		case 2:
			Horde_Menu();
			break;
		case 3:
			int i = 1;
			cout << "������ ĳ����" << endl;
			for (auto iter = vec_pCharacterList.begin(); iter != vec_pCharacterList.end(); iter++,i++)
			{
				cout << i << "." << (*iter)->GetName() <<"(" << (*iter)->GetCampName() << ")" << endl;
				delete *iter;
			}
			AllianceCamp::GetInstans()->Release();
			HordeCamp::GetInstans()->Release();
			exit(1);
			break;
		}
	}

}