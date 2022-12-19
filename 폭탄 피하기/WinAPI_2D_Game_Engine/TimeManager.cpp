#include "TimeManager.h"
namespace ENGINE
{
	VOID TimeManager::Initialize(UINT32  FPS)
	{
		//타임메니저의 fps는 1000분의 120fps이다.
		this->FPS = 1000 / FPS;
		//GetTickCount64 : 윈도우가 시작되고 나서부터의 경과 시간을 확인(구동시간 확인)
		//초기화 되었을때 의 시간을 저장
		currTime = lastTime = GetTickCount64();
	}

	BOOL TimeManager::Update()
	{
		//업데이트 될때 시간을 수정
		currTime = GetTickCount64();

		//지연값은 : 현재시간 - 이전시간
		elapsed = (currTime - lastTime);
		//지연값이 this->fps의 값보다 작으면 FALSE
		if (elapsed < FPS) return FALSE;
		//지연 값이 this->fps의 값보다 크면 
		//지연 시간은 (현재시간 - 이전시간)*0.001f
		elapseTime = elapsed * 0.001f;
		//이전 시간 을 수정
		lastTime = currTime;

		return TRUE;
	}
}
