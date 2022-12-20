#pragma once

#include "EngineMecro.h"

// #define SINGLETON_H �Ǿ� ���� ������ �Ʒ��� �ڵ带 ����.
#ifndef SINGLETON_H
#define SINGLETON_H 

//T��� ������ ������ ������ ����
template <typename T>

class Singleton
{
	//�̱��� �ܿ����� ȣ������ ���ϰ� ����
private:
	//�̱��� ������� �������� ���� ����Ʈ
	static T* instance;
	//�̱��� �ܿ����� ȣ������ ���ϰ� ��ȣ
protected:
	//������ ��ȣ
	Singleton() {}
public:
	//
	static T* GetInstance()
	{
		if (nullptr == instance) instance = new T;
		return instance;
	}
	static void Destroy() { DEL(instance); }
};
template<typename T>T* Singleton<T>::instance = nullptr;
#endif // !SINGLETON_H
