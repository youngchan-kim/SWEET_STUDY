#pragma once
//TimeManager클래스의 생성자가 private이기 때문에 Singleton class를 friend로 만들어 준다.
//TimeManager.h
#include "Singleton.h"
#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H
namespace ENGINE
{
	class TimeManager : public Singleton<TimeManager>
	{
	private:
		UINT32 FPS;
		FLOAT elapseTime;
		ULONGLONG currTime, lastTime, elapsed;

		TimeManager() : FPS(0), elapseTime(0.0f), currTime(0), lastTime(0) {}
	public:
		VOID Initialize(UINT32 FPS);
		BOOL Update();
		FLOAT DeltaTime() CONST { return elapseTime; }

		friend Singleton;
		// friend 해주는 이유
		// TimeManager가 Singleton을 상속 받고 있다.
		// friend로 선언된 대상에게 private, protected는 public으로 작용한다.
		// Singleton에서 TimeManager의 생성자를 사용해야한다. 그런데 
		// private로 TimeManager의 생성자를 제한 했기 때문에 Singleton에서 쓸 수 있게 해준다.
	};
#define TimeMgr TimeManager::GetInstance()
}
#endif // !TIME_MANAGER_H

