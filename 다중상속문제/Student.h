#pragma once
#include "Person.h"
#include "School.h"
class Student : public Person, School
{
public:
	void Input();
	void Output();
	Student();
	~Student();
};

