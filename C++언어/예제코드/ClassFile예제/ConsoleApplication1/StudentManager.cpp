#include "StudentManager.h"



StudentManager::StudentManager()
{
}

void StudentManager::AddStudent()
{
	if (m_iStudentCount < STUDENT_MAX)
	{
		m_StudentList[m_iStudentCount].SetStudent(m_iStudentCount + 1);
		m_iStudentCount++;
	}
	else
		cout << "더이상 학생을 등록할 수 없습니다." << endl;
}

void StudentManager::ShowStudentList()
{
	for (int i = 0; i < m_iStudentCount; i++)
		m_StudentList[i].ShowStudent();
}

bool StudentManager::FindStudentName(string Name)
{
	bool Flag = false;
	for (int i = 0; i < m_iStudentCount; i++)
	{
		if (m_StudentList[i].GetName() == Name)
		{
			m_StudentList[i].ShowStudent();
			Flag = true;
		}
	}
	return Flag;
}

StudentManager::~StudentManager()
{
}
