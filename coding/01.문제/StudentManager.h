#pragma once
#include"Student.h"

#define STUDENT_MAX 10

class StudentManager
{
private:
	int m_iStudentCount = 0;
	Student m_StudentList[STUDENT_MAX];
public:
	void AddStudent();
	void ShowStudentList();
	void ShowStudentClassList();
	inline int GetStudentCount()
	{
		return m_iStudentCount;
	}
	bool FindStudentName(string Name);
	bool FindStudentClass();
	StudentManager();
	~StudentManager();
};