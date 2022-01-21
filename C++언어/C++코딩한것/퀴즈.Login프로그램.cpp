#include<iostream>
#include<Windows.h>
#include<list> 
using namespace std;

#define TURE 1
#define MILEAGE_POINT 1000
#define NULL 0
#define ID_LENGTH 3
#define PW_LENGTH 8

typedef struct Member
{
	string id;
	string pw;
	string nickname;
	string phone;
	int age;
	int point;
}Member;

bool Id_Check(list<Member> member, string inputid)
{
	for (list<Member>::iterator iter = member.begin(); iter != member.end(); iter++)
	{
		if (inputid == iter->id)
		{
			cout << "������ ���̵� �ֽ��ϴ�." << endl;
			return false;
		}
	}
	return true;
}

bool Id_ComParison(string inputid)
{
	bool id_comparison = true;
	for (int j = 0; j < inputid.length(); j++)
	{
		if ((inputid[j] < 'A' || inputid[j] > 'Z') && (inputid[j] < 'a' || inputid[j] > 'z') && (inputid[j] < '0' || inputid[j] > '9'))
		{
			cout << "id�� ������ �ƴմϴ�." << endl;
			id_comparison = false;
			break;
		}
	}
	if (inputid.length() < ID_LENGTH)
	{
		cout << "id�� ������ �����Դϴ�." << endl;
		id_comparison = false;
	}
	return id_comparison;
}
bool Pw_ComParison(string password)
{
	bool booldata = true;
	if (password.length() < PW_LENGTH)
	{
		cout << "��й�ȣ�� 8���� �̻� �����ּ���"<<endl;
		booldata = false;
	}
	for (int j = 0; j < password.length(); j++)
	{
		if ((password[j] < 'A' || password[j] > 'Z') && (password[j] < 'a' || password[j] > 'z') && (password[j] < '0' || password[j] > '9'))
		{
			cout << "��й�ȣ�� ������ �ƴմϴ�." << endl;
			return false;
		}
	}
	return booldata;
}
bool Pw_HaveNumber(string password)
{
	for (int j = 0; j < password.length(); j++)
	{
		if (password[j] >= '0' && password[j] <= '9')
			return true;
	}
	cout << "���ڰ� ���ԵǾ� ���� �ʽ��ϴ�." << endl;
	return false;
}

void Rest_Imformation(Member *membership)
{
	system("cls");
	cout << "�г��� �Է� : ";
	cin >> membership->nickname;
	cout << "���� �Է� : ";
	cin >> membership->age;
	cout << "�޴��� ��ȣ �Է� : ";
	cin >> membership->phone;
	membership->point = MILEAGE_POINT;
	cout << "ȸ������ ���� !! ���ϸ��� " << membership->point << "�� ���" << endl;;
	system("pause");
}
void Input_ID(list<Member> member, Member *membership)
{
	string inputid;
	bool id_check,id_comparison;
	while (TRUE)
	{
		system("cls");
		cout << "���̵� �Է�([3���ڡ�] AND [�ѱ�X]) : ";
		cin >> inputid;

		id_check = Id_Check(member, inputid);
		id_comparison = Id_ComParison(inputid);
		if ((id_check == true)&&(id_comparison == true))
		{
			membership->id = inputid;
			break;
		}
		system("pause");
	}
}
void Input_PW(list<Member> member, Member* membership)
{
	string password, verifypassword;
	bool check_pw = false, haveNumber = false;

	while (TRUE)
	{
		system("cls");
		cout << "��й�ȣ �Է�([8���ڡ�]AND[����]AND[���� ����]) : ";
		cin >> password;
		cout << "��й�ȣ Ȯ�� : ";
		cin >> verifypassword;

		if (password != verifypassword)
			cout << "��й�ȣ�� ���� �ʽ��ϴ�." << endl;
		else
		{
			check_pw = Pw_ComParison(password);
			haveNumber = Pw_HaveNumber(password);
			if((check_pw == true)&&(haveNumber == true))
			{
				membership->pw = password;
				break;
			}
		}
		system("pause");
	}
}

Member SignUp(list<Member> member)
{
	Member membership;
	
	Input_ID(member, &membership);
	Input_PW(member, &membership);
	Rest_Imformation(&membership);

	return membership;

}
void Profile(list<Member>::iterator iter)
{
	cout << "===================" << endl << "ID : " << iter->id << "\t�г��� : " << iter->nickname << endl << "���� : " << iter->age << "\t�޴��� ��ȣ : " << iter->phone << endl << "���ϸ��� : " << iter->point << endl;
}
list<Member>::iterator Modify_ID(list<Member>::iterator iter)
{
	string modifyid;
	cout << "���� �г��� : " << iter->nickname << endl;
	cout << "������ �г��� �Է� : ";
	cin >> modifyid;
	cout << iter->nickname << "->" << modifyid << endl;
	iter->nickname = modifyid;
	return iter;
}
list<Member>::iterator Modify_AGE(list<Member>::iterator iter)
{
	int modifyage;
	cout << "���� ���� : " << iter->age << endl;
	cout << "������ ���� �Է� : ";
	cin >> modifyage;
	cout << iter->age << "->" << modifyage << endl;
	iter->age = modifyage;
	return iter;
}
list<Member>::iterator Modify_PHONE(list<Member>::iterator iter)
{
	int modifyphone;
	cout << "���� �޴��� ��ȣ : " << iter->phone << endl;
	cout << "������ �޴��� ��ȣ �Է� : ";
	cin >> modifyphone;
	cout << iter->phone << "->" << modifyphone << endl;
	iter->phone = modifyphone;
	return iter;
}
list<Member>::iterator Modify(list<Member>::iterator iter)
{
	int num;
	while (TRUE)
	{
		system("cls");
		Profile(iter);
		cout << "===================" << endl;
		cout << "1.�г��� ����" << endl;
		cout << "2.���� ����" << endl;
		cout << "3.�޴��� ��ȣ ����" << endl;
		cout << "4.���ư���" << endl;
		cout << "�Է� : ";
		cin >> num;
		switch (num)
		{
		case 1:
			iter = Modify_ID(iter);
			system("pause");
			break;
		case 2:
			iter = Modify_AGE(iter);
			system("pause");
			break;
		case 3:
			iter = Modify_PHONE(iter);
			system("pause");
			break;
		case 4:
			return iter;
		}
	}
}

list<Member>::iterator Login(list<Member>::iterator iter)
{
	int num;
	while (TRUE)
	{
		system("cls");
		cout << "========Menu========" << endl;
		cout << "1.ȸ�� ����" << endl;
		cout << "2.ȸ�� ���� ����" << endl;
		cout << "3.�α׾ƿ�" << endl;
		cout << "�Է� : ";
		cin >> num;
		switch (num)
		{
		case 1:
			Profile(iter);//ȸ�� ���� �Լ�
			system("pause");
			break;
		case 2:
			iter = Modify(iter);//ȸ�� ���� �Լ��� �̿��� ���� ���� �Լ�
			break;
		case 3:
			return iter;
		}
	}

	
}
void Release(std::list<Member>* iList)
{
	while (!iList->empty())
	{
		iList->pop_back();
	}
}

void main()
{
	list<Member> member;
	string inputid, verifypassword;
	list<Member>::iterator iter;
	int list, i = 0;
	bool check = false;

	while (TURE)
	{
		system("cls");
		cout << "=====Login=====(ȸ����[" << i << "]��)" << endl;
		cout << "\t1.ȸ�� ����" << endl;
		cout << "\t2.�α���" << endl;
		cout << "\t3.����" << endl;
		cout << "�Է� : ";
		cin >> list;
		switch (list)
		{
		case 1:
			if (i != 10)
			{
				member.push_back(SignUp(member));
				i++;
			}
			else
				cout << "�� �̻� ȸ�������� �� �� �����ϴ�.";
			break;
		case 2:
			if (!member.empty())
			{
				while (TRUE)
				{
					system("cls");
					cout << "���̵� �Է� : ";
					cin >> inputid;
					cout << "��� ��ȣ �Է� : ";
					cin >> verifypassword;
					for (iter = member.begin(); iter != member.end(); iter++)
					{
						if ((iter->id == inputid) && (iter->pw == verifypassword))
						{
							iter = Login(iter);
							check = true;
							break;
						}
					}
					if(check == true)
					break;
				}
			}
			else
				cout << "���Ե� ȸ���� �����ϴ�." << endl << "ȸ�������� ���� ���ּ���" << endl;
			break;

		case 3:
			Release(&member);
			return;
		}

	}
}