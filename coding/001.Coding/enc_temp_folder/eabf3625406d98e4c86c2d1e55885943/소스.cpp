#include"StudentManager.h"
#include<Windows.h>

void main()
{
	int Select;
	StudentManager SManager;
	string strTmp;
	bool bTmp;
	while (1)
	{
		system("cls");
		cout << "======�л����� ���α׷�======" << endl;
		cout << "      1.�л� ���" << endl;
		cout << "      2.�л� ���<��ȣ��>" << endl;
		cout << "      3.�л� ���<�г��>" << endl;
		cout << "      4.�л� �˻�" << endl;
		cout << "      5.�г� �˻�" << endl;
		cout << "      6.������ �л� ����" << endl;
		cout << "      7.�л� ��ü ����" << endl;
		cout << "      8.����" << endl;
		cout << "   (�л� �� : " << SManager.GetStudentCount() << ")" << endl;
		cout << "�Է� : ";
		cin >> Select;
		system("cls");
		switch (Select)
		{
		case 1:
			SManager.AddStudent();
			break;
		case 2:
			SManager.ShowStudentList();
			break;
		case 3:
			cout << "�̸� �Է� : ";
			cin >> strTmp;
			bTmp = SManager.FindStudentName(strTmp);
			if (bTmp == false)
				cout << "�ش� �л��� �����ϴ�." << endl;
			break;
		case 4:
			return;
		}
		system("pause");
	}
}