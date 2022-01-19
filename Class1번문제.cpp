#include <iostream>
#include <string>
using namespace std;

#define MIN 2
#define MAX 10
#define TRUE 1

enum GOGODAN
{
	GOGODAN_ONE = 1,
	GOGODAN_TWO,
	GOGODAN_THREE,
	GOGODAN_FOUR,
	GOGODAN_FIVE,
	GOGODAN_SIX,
	GOGODAN_SEVEN,
	GOGODAN_EIGHT,
	GOGODAN_NINE,
	GOGODAN_END,
};

class GogodanNum
{
private:
	int startnum, endnum;
	GOGODAN Gogodan;
public:
	void SetUsingNum(int _startnum, int _endnum);
	bool Different(int _startnum, int _endnum);
	void ShowPerson();
};

void GogodanNum::SetUsingNum(int _startnum, int _endnum)
{
	startnum = _startnum;
	endnum = _endnum + 1;
}

bool GogodanNum::Different(int _startnum, int _endnum)
{
	if ((MIN > startnum && startnum > MAX))
	{
		cout << "���� ���� 2���� �۰ų� 9���� Ů�ϴ�.";
		return false;
	}
	else if ((MIN > endnum && endnum > MAX))
	{
		cout << "�� ���� 2���� �۰ų� 9���� Ů�ϴ�.";
		return false;
	}
	else
		return true;
}

void GogodanNum::ShowPerson()
{
	for (int i = startnum; i < endnum; i++)
	{
		cout << "========" << i << "��========\t";
	}
	cout << endl;
	for (int j = GOGODAN_ONE; j < GOGODAN_END; j++)
	{
		for (int i = startnum; i < endnum; i++)
		{
			cout << "   " << i << " X " << j << "=" << i * j << "\t\t";
		}
		cout << endl;
	}
}

void main()
{
	int start, end;
	bool overnum;
	GogodanNum gogodan;

	while (TRUE);
	{
		cout << "���� �� �Է� : ";
		cin >> start;
		cout << "�� �� �Է� : ";
		cin >> end;
		gogodan.SetUsingNum(start, end);
		overnum = gogodan.Different(start, end);

		if (overnum == true)
		{
			gogodan.ShowPerson();
			return;
		}
	}
}