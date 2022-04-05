#pragma once
#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

class Person
{
private:
	string str_mgender, str_mname;
	int i_mage;
public :
	void Information();
	void Print();
	Person();
	~Person();

};

