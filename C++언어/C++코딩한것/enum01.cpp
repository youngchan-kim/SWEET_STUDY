#include <iostream>

using namespace std;

enum WEEK
{
	WEEK_SUN,
	WEEK_MON,
	WEEK_TUE,
	WEEK_WED,
	WEEK_THU,
	WEEK_FRI,
	WEEK_SAT
};

void main()
{
	WEEK today = WEEK_MON;
	switch (today)
	{
		case WEEK_SUN:
			cout << "�Ͽ��� �Դϴ�.";
			break;
		case WEEK_MON:
			cout << "������ �Դϴ�.";
			break;
		case WEEK_TUE:
			cout << "ȭ���� �Դϴ�.";
			break;
		case WEEK_WED:
			cout << "������ �Դϴ�.";
			break;
		case WEEK_THU:
			cout << "����� �Դϴ�.";
			break;
		case WEEK_FRI:
			cout << "�ݿ��� �Դϴ�.";
			break;
		case WEEK_SAT:
			cout << "����� �Դϴ�.";
			break;
	}
}


