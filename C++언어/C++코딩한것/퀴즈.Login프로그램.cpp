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
			cout << "동일한 아이디가 있습니다." << endl;
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
			cout << "id가 영문이 아닙니다." << endl;
			id_comparison = false;
			break;
		}
	}
	if (inputid.length() < ID_LENGTH)
	{
		cout << "id가 세글자 이하입니다." << endl;
		id_comparison = false;
	}
	return id_comparison;
}
bool Pw_ComParison(string password)
{
	bool booldata = true;
	if (password.length() < PW_LENGTH)
	{
		cout << "비밀번호를 8글자 이상 적어주세요"<<endl;
		booldata = false;
	}
	for (int j = 0; j < password.length(); j++)
	{
		if ((password[j] < 'A' || password[j] > 'Z') && (password[j] < 'a' || password[j] > 'z') && (password[j] < '0' || password[j] > '9'))
		{
			cout << "비밀번호가 영문이 아닙니다." << endl;
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
	cout << "숫자가 포함되어 있지 않습니다." << endl;
	return false;
}

void Rest_Imformation(Member *membership)
{
	system("cls");
	cout << "닉네임 입력 : ";
	cin >> membership->nickname;
	cout << "나이 입력 : ";
	cin >> membership->age;
	cout << "휴대폰 번호 입력 : ";
	cin >> membership->phone;
	membership->point = MILEAGE_POINT;
	cout << "회원가입 성공 !! 마일리지 " << membership->point << "원 등록" << endl;;
	system("pause");
}
void Input_ID(list<Member> member, Member *membership)
{
	string inputid;
	bool id_check,id_comparison;
	while (TRUE)
	{
		system("cls");
		cout << "아이디 입력([3글자↑] AND [한글X]) : ";
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
		cout << "비밀번호 입력([8글자↑]AND[영문]AND[숫자 포함]) : ";
		cin >> password;
		cout << "비밀번호 확인 : ";
		cin >> verifypassword;

		if (password != verifypassword)
			cout << "비밀번호가 같지 않습니다." << endl;
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
	cout << "===================" << endl << "ID : " << iter->id << "\t닉네임 : " << iter->nickname << endl << "나이 : " << iter->age << "\t휴대폰 번호 : " << iter->phone << endl << "마일리지 : " << iter->point << endl;
}
list<Member>::iterator Modify_ID(list<Member>::iterator iter)
{
	string modifyid;
	cout << "현재 닉네임 : " << iter->nickname << endl;
	cout << "변경할 닉네임 입력 : ";
	cin >> modifyid;
	cout << iter->nickname << "->" << modifyid << endl;
	iter->nickname = modifyid;
	return iter;
}
list<Member>::iterator Modify_AGE(list<Member>::iterator iter)
{
	int modifyage;
	cout << "현재 나이 : " << iter->age << endl;
	cout << "변경할 나이 입력 : ";
	cin >> modifyage;
	cout << iter->age << "->" << modifyage << endl;
	iter->age = modifyage;
	return iter;
}
list<Member>::iterator Modify_PHONE(list<Member>::iterator iter)
{
	int modifyphone;
	cout << "현재 휴대폰 번호 : " << iter->phone << endl;
	cout << "변경할 휴대폰 번호 입력 : ";
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
		cout << "1.닉네임 변경" << endl;
		cout << "2.나이 변경" << endl;
		cout << "3.휴대폰 번호 변경" << endl;
		cout << "4.돌아가기" << endl;
		cout << "입력 : ";
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
		cout << "1.회원 정보" << endl;
		cout << "2.회원 정보 변경" << endl;
		cout << "3.로그아웃" << endl;
		cout << "입력 : ";
		cin >> num;
		switch (num)
		{
		case 1:
			Profile(iter);//회원 정보 함수
			system("pause");
			break;
		case 2:
			iter = Modify(iter);//회원 정보 함수를 이용한 정보 변경 함수
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
		cout << "=====Login=====(회원수[" << i << "]명)" << endl;
		cout << "\t1.회원 가입" << endl;
		cout << "\t2.로그인" << endl;
		cout << "\t3.종료" << endl;
		cout << "입력 : ";
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
				cout << "더 이상 회원가입을 할 수 없습니다.";
			break;
		case 2:
			if (!member.empty())
			{
				while (TRUE)
				{
					system("cls");
					cout << "아이디 입력 : ";
					cin >> inputid;
					cout << "비밀 번호 입력 : ";
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
				cout << "가입된 회원이 없습니다." << endl << "회원가입을 먼저 해주세요" << endl;
			break;

		case 3:
			Release(&member);
			return;
		}

	}
}