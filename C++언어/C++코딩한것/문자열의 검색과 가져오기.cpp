#include<iostream>
#include<string>
using namespace std;

void main()
{
	string str = "Education is the best provision for old age.\n - Aristotle";
	int index = str.find("provision");
	cout << "Find Provision = " << index << endl;
	cout << str[index] << endl;
	cout << str.substr(index, sizeof("provision"));//substr: Ư�� ���ڸ� �߶��ִ� �Լ� 
	return;
} 

//��ã�� ��� string::npos ��ȯ
