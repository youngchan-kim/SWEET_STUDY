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
		cout << "======학생관리 프로그램======" << endl;
		cout << "      1.학생 등록" << endl;
		cout << "      2.학생 목록" << endl;
		cout << "      3.학생 이름 검색" << endl;
		cout << "      4.종료" << endl;
		cout << "   (학생 수 : " << SManager.GetStudentCount() << ")" << endl;
		cout << "입력 : ";
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
			cout << "이름 입력 : ";
			cin >> strTmp;
			bTmp = SManager.FindStudentName(strTmp);
			if (bTmp == false)
				cout << "해당 학생이 없습니다." << endl;
			break;
		case 4:
			return;
		}
		system("pause");
	}
}