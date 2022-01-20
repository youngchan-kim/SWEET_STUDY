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
		cout << "시작 단 입력 : ";
		cin >> startnum;
		cout << "끝 단 입력 : ";
		cin >> endnum;

		if (startnum < MIN || startnum > MAX)
			cout << "시작 단이 2보다 작거나 9보다 큽니다." << endl;
		else if (endnum < MIN || endnum > MAX)
			cout << "끝 단이 2보다 작거나 9보다 큽니다." << endl;
	} while ((startnum < MIN || startnum > MAX) || (endnum < MIN || endnum > MAX));
	ShowGogodan();
}

void GogodanNum::ShowGogodan()
{
	for (int i = startnum; i <= endnum; i++)
	{
		cout << "========" << i << "단========\t";
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