#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;

#define STUDENTMAX 50



void main()
{
	int Select, StudentCount = 0;
	string* student[STUDENTMAX];
	while (1)
	{
		system("cls");
		cout << "===학생정보관리===(학생수 : " << StudentCount << "명)" << endl;
		cout << "   1.학생등록" << endl;
		cout << "   2.학생정보 보기" << endl;
		cout << "   3.종료" << endl;
		cout << " 입력 : " << endl;
		cin >> Select;
		switch (Select)
		{
		case 1:
			if (StudentCount < STUDENTMAX)
			{
				student[StudentCount] = new string;
				cout << StudentCount + 1 << "번 학생 이름 : ";
				cin >> *student[StudentCount++];
			}
			break;
		case 2:
			for (int i = 0; i < StudentCount; i++)
				cout << i + 1 << "번 학생 : " << *student[i] << endl;
			system("pause");
			break;
		case 3:
			for (int i = 0; i < StudentCount; i++)
			{
				cout << i + 1 << "번 학생 : " << *student[i] << endl;
				delete student[i];
				cout << "할당 해제 완료" << endl;
			}
			system("pause");
			return;
		}
	}
}


