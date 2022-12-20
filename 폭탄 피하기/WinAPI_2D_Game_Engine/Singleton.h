#pragma once

#include "EngineMecro.h"

// #define SINGLETON_H 되어 있지 않으면 아래의 코드를 쓴다.
#ifndef SINGLETON_H
#define SINGLETON_H 

//T라는 임의의 형식의 변수를 만듦
template <typename T>

class Singleton
{
	//싱글톤 외에서는 호출하지 못하게 제한
private:
	//싱글톤 헤드파일 한정으로 전역 포인트
	static T* instance;
	//싱글톤 외에서는 호출하지 못하게 보호
protected:
	//생성자 보호
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
