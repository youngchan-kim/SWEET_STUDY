#include<iostream>
#include<Windows.h>
using namespace std;

class Quiz
{
private:
	int m_itime = 8, m_isalary = 7500;
	int m_ixnum = 10;
	int m_imin = 2, m_imax = 9;
public:
	void Menu();
	void Employee_Salary(int time, int salary);
	void Employee_Print(int time, int salary, int day);
	void Sum_From_1_to_x(int m_ixnum);
	void Sum_Print(int m_ixnum);
	void Multiply(int m_imin, int m_imax);
	void Multiply_Print(int m_imin, int m_imax);
};
void Quiz::Menu()
{
	int list;
	while (1)
	{
		system("cls");
		cout << "문제 1. 시급 계산" << endl << "문제 2. 1~x수 까지의 합" << endl;
		cout << "문제 3. 구구단 출력" << endl << "     4. 종료" << endl << "     입력 : ";
		cin >> list;

		switch (list)
		{
		case 1:
			Employee_Salary(m_itime, m_isalary);
			break;
		case 2:
			Sum_From_1_to_x(m_ixnum);
			break;
		case 3:
			Multiply(m_imin, m_imax);
			break;
		case 4:
			return;
		}
	}
}
void Quiz::Employee_Print(int time, int salary, int day)
{
	int finalsalary;
	finalsalary = day * time * salary;
	cout << "시급 : " << salary << endl;
	cout << "시간 : " << time << " 시간   " << "일 수 : " << day << " 일" << endl;
	cout << "급여 : " << finalsalary << endl;
	system("pause");
}
void Quiz::Employee_Salary(int m_itime, int m_isalary)
{
	int day, yesno;
	while (1)
	{
		system("cls");
		cout << "몇일 근무하셨습니까?" << endl;
		cin >> day;
		cout << "시간과 임금을 입력 하시겠습니까?" << endl;
		cout << "(Yes 1, No 2)" << endl;
		cin >> yesno;
		if (yesno == 1)
		{
			cout << "시급 입력 : ";
			cin >> m_isalary;
			cout << "시간 입력 : ";
			cin >> m_itime;
			Employee_Print(m_itime, m_isalary, day);
			break;
		}
		else if (yesno == 2)
		{
			Employee_Print(m_itime, m_isalary, day);
			break;
		}
		else
		{
			cout << "잘 못 입력하셨습니다." << endl << " 다시 입력해 주세요" << endl;
			system("pause");
		}
	}
}
void Quiz::Sum_Print(int m_ixnum)
{
	int all_sum = 0;
	for (int i = 1; i <= m_ixnum; i++)
	{
		all_sum += i;
	}
	cout << "1 ~ " << m_ixnum << " 총 합 : " << all_sum << endl;
	system("pause");
}
void Quiz::Sum_From_1_to_x(int m_ixnum)
{
	int yesno;
	while(1)
	{
		system("cls");
		cout << "최종 값을 변경하시겠습니까? " << endl;
		cout << "(Yes 1, No 2)" << endl;
		cin >> yesno;
		if (yesno == 1)
		{
			cout << "최대 값 입력 : ( 현재 : 10) ";
			cin >> m_ixnum;
			Sum_Print(m_ixnum);
			break;
		}
		else if (yesno == 2)
		{
			Sum_Print(m_ixnum);
			break;
		}
		else
		{
			cout << "잘 못 입력하셨습니다." << endl << " 다시 입력해 주세요" << endl;
			system("pause");
		}
	}
}
void Quiz::Multiply_Print(int m_imin, int m_imax)
{
	for (int i = m_imin; i <= m_imax; i++)
	{
		cout << "===" << i << " 단===\t";
	}
	cout << endl;
	for (int j = 1; j <= 8; j++)
	{
		for (int i = m_imin; i <= m_imax; i++)
		{
			cout << i << " x " << j << " = " << i * j << " \t";
		}
		cout << endl;
	}

	system("pause");
}
void Quiz::Multiply(int m_imin, int m_imax)
{
	int yesno;
	while (1)
	{
		system("cls");
		cout << "최종 값을 변경하시겠습니까? " << endl;
		cout << "(Yes 1, No 2)" << endl;
		cin >> yesno;
		if (yesno == 1)
		{
			while (1)
			{
				cout << "최소 값 입력 : ";
				cin >> m_imin;
				cout << "최대 값 입력 : ";
				cin >> m_imax;
				if (m_imin > m_imax)
					cout << "최대 값이 최소 값보다 작습니다." << endl << "다시 입력 해 주세요." << endl;
				else
					break;
			}
			Multiply_Print(m_imin, m_imax);
			break;
		}
		else if (yesno == 2)
		{
			Multiply_Print(m_imin, m_imax);
			break;
		}
		else
		{
			cout << "잘 못 입력하셨습니다." << endl << "다시 입력해 주세요" << endl;
			system("pause");
		}
	}
}
void main()
{
	Quiz quiz;
	quiz.Menu();
	
}