#include<iostream>
#include<Windows.h>
#include"Figure.h"
#include"Triangle.h"
#include"circle.h"
#include"Quadrangle.h"
using namespace std;

Figure* SelectFigure()
{
	system("cls");
	int select;
	Figure* tmp;
	cout << "=== ���� ���� ===" << endl;
	cout << "  1. �ﰢ��" << endl;
	cout << "  2. �簢�� " << endl;
	cout << "  3. ����" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
		tmp = new Triangle;
		tmp->SetSize();
		break;
	case 2:
		tmp = new Quadrangle;
		tmp->SetSize();
		break;
	case 3:
		tmp = new circle;
		tmp->SetSize();
		break;
	}
	return tmp;
}

void Show_Figure(Figure* figure_list[])
{
	int i;
	for (i = 0; figure_list[i] != NULL; i++)
	{
		figure_list[i]->Draw();
	}
	if (i == 0)
		cout << " ��ϵ� ������ �����ϴ�."<<endl;
	system("pause");
}

void Exit()
{
	for (int i = 5; i >= 0; i--)
	{
		system("cls");
		cout << "���� �մϴ�." << endl;
		cout << i << "����" << endl;
		Sleep(1000);
	}
	exit(1);
}

void main()
{
	Figure* figure_list[50] = { NULL };
	int select;
	while (1)
	{
		system("cls");
		cout << "=== ���� �׸��� ===" << endl;
		cout << "  1. ���� �߰�" << endl;
		cout << "  2. ���� ��ü �׸���" << endl;
		cout << "  3. ���� " << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			int i;
			for (i = 0; i < 50; i++)
			{
				if (figure_list[i] == NULL)
					break;
			}
			figure_list[i] = SelectFigure();
			break;
		case 2:
			Show_Figure(figure_list);
			break;
		case 3:
			Exit();
			break;
		default:
			break;
		}
	}
}