#include "SpriteAnimation.h"
#include "SpriteRenderer.h"
#include "../TimeManager.h"


//루프 뿐만 아니라 원스도 되도록 수정할 것
namespace ENGINE
{
	SpriteAnimation::SpriteAnimation(UINT divX, UINT divY, BOOL autoPlay, BOOL Loop) :
		AnimationComponent(divY, divX, autoPlay, isLoop),
		frame(0), animTimer(frameRate), renderer(nullptr)
	{ }

	//조금 수정해서 루프도 되고 한번만 재생도 되도록할것
	VOID SpriteAnimation::Operate(GameObject* Owner)
	{
		//게임오브젝트 중 그래픽 컴포넌트를 renderer에 대입한다. 
		renderer = Owner->GetComponent(ComponentType::Graphic);
		if (!renderer) return;

		//frame은 renderer에 있는 장면의 가짓수
		//index은 renderer에 있는 장면의 종류
		static_cast<SpriteRenderer*>(renderer)->SetSrc(frame, index);

		// isPlaying가 false면 실행하지 않는다.
		if (!isPlaying)
		{
			//첫 애니매이션으로 초기화
			frame = 0;
			//frameRate== 프레임당 걸리는 시간을  animTimer에 대입한다.
			animTimer = frameRate;
			return;
		}

		// 여기서 무한 루프가 생긴다.
		// BOOL isLoop
		//animTimer : 프레임당 걸리는 시간
		//프레임에 걸리는 시간에 (딜레이타임 곱하기 스피드)를 더한다.

		animTimer += TimeMgr->DeltaTime() * speed;
		//프레임당 걸리는 시간보다 애니매이션 재생시간이 크다면
		if (frameRate <= animTimer)
		{
			//애니매이션 재생시간을 초기화한다.
			animTimer -= frameRate;
			//isReverse 는 스피드가 0이면 true이다. true이면 -1 false이면 1을 더한다.
			// 프레임을 넘겨주는 라인

			if (!isLoop && frame >= (int)(length-1))
			{
				isPlaying = false;
				return;
			}
			//프레임 증가
			frame += (isReverse ? -1 : 1);
			//프레임 체크후 마지막이면 처음으로 돌려줌
			frame = Repeat(frame, (int)(length - 1));
		}
	}
	//루프란 계속 도는 것
	//원스란 한번 돌면 더이상 돌지 않는것
	//루프에 한번 돌았다는 표시를 해주고 표시를 특정 상황에서만 초기화함
	VOID SpriteAnimation::Reset()
	{
		index = 0U;
		speed = 1U;
		frame = 0;
		animTimer = frameRate;
	}
}


//코드파악하는 노하우를 익히려고 