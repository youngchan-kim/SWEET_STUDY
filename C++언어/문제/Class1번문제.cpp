#include <iostream>
#include <string>
using namespace std;

#define MIN 2
#define MAX 10
#define TRUE 1

class GogodanNum
{
private:
	int startnum, endnum;
public:
	void SetUsingNum();
	void ShowGogodan();
};

void GogodanNum::SetUsingNum()
{
	do
	{
		cout << "���� �� �Է� : ";
		cin >> startnum;
		cout << "�� �� �Է� : ";
		cin >> endnum;

		if (startnum < MIN || startnum > MAX)
			cout << "���� ���� 2���� �۰ų� 9���� Ů�ϴ�." << endl;
		else if (endnum < MIN || endnum > MAX)
			cout << "�� ���� 2���� �۰ų� 9���� Ů�ϴ�." << endl;
	} while ((startnum < MIN || startnum > MAX) || (endnum < MIN || endnum > MAX));
	ShowGogodan();
}

void GogodanNum::ShowGogodan()
{
	for (int i = startnum; i <= endnum; i++)
	{
		cout << "========" << i << "��========\t";
	}
	cout << endl;
	for (int j = 1; j < 10; j++)
	{
		for (int i = startnum; i <= endnum; i++)
		{
			cout << "   " << i << " X " << j << "=" << i * j << "\t\t";
		}
		cout << endl;
	}
}

void main()
{
	GogodanNum gogodan;

	gogodan.SetUsingNum();
}