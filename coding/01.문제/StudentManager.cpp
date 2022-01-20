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
		cout << "���̻� �л��� ����� �� �����ϴ�." << endl;
}

void StudentManager::ShowStudentList()
{
	for (int i = 0; i < m_iStudentCount; i++)
		m_StudentList[i].ShowStudent();
}

void  StudentManager::ShowStudentClassList()
{

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

bool StudentManager::FindStudentClass()
{
	int classnum;
	cin >> classnum;
	for (int i = 0; i < m_iStudentCount; i++)
	{
		if (classnum == m_StudentList[i].GetClass())
		{
			m_StudentList[i].ShowStudent();
		}
	}
}

StudentManager::~StudentManager()
{
}
