#include<iostream>
#include<string>
using namespace std;

void main()
{
	string str;
	while (1)
	{
		system("cls");
		cout << "Very�� �Է��Ͻÿ� : ";
		cin >> str;
		if (str == "Very")
		{
			str += "Good";
			cout << str << endl;
			break;
		}
		cout << "�߸� �Է� �ٽ�" << endl;
		system("pause");
	}return;
}