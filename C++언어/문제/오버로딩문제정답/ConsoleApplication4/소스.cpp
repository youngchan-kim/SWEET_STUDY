#include"Quiz.h"

#define ARRMAX 5

void main()
{
	int num1, num2, iarr[ARRMAX];
	char ch, charr[ARRMAX];
	string str1, str2;
	Quiz quiz;
	cout << "1.���� 2�� �Է� :";
	cin >> num1 >> num2;
	quiz.Quiz1(num1, num2);
	cout << "1.���Ϲ��ڿ� ���� �Է� :";
	cin >> ch >> num1;
	quiz.Quiz1(ch, num1);
	cout << "2.���ڿ� �ϳ� �Է� : ";
	cin >> str1;
	quiz.Quiz2(str1);
	cout << "2.���ڿ� �ΰ� �Է� : ";
	cin >> str1 >> str2;
	quiz.Quiz2(str1, str2);
	cout << "3.���� 5�� �Է� : ";
	for (int i = 0; i < ARRMAX; i++)
		cin >> iarr[i];
	quiz.Quiz3(iarr,ARRMAX);
	cout << "3.���Ϲ��� 5�� �Է� : ";
	for (int i = 0; i < ARRMAX; i++)
		cin >> charr[i];
	quiz.Quiz3(charr, ARRMAX);
}