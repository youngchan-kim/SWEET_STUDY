#pragma once
#include "EngineMecro.h"
#include "Components/SpriteRenderer.h"
#include "Components/SpriteAnimation.h"
#include "Components/LRInput.h"
#include "UIManager.h"

using namespace ENGINE;
//플레이어는 게임오브젝트 클래스와 씬 인터페이스를 상속 받는다. // 씬 인터페이스를 상속 받지 않아도 된다.
class Player : public GameObject
{
	//플레이어가 가지는 정보 // 위치 정보인지 몇조각인지
	enum Data { SpritesX = 4, SpritesY = 2, Speed = 200 };

	//플레이어 그림중 특정 부분만 그려주는 클래스의 포인트변수명
	SpriteRenderer* renderer;

	//애니메이션의 정보클래스의 포인트 변수명
	AnimationComponent* anim;

	//방향키의 정보를 얻는 포인트변수
	LRInput* input;

	RECT player_rect;
public:
	Player();
	

	// 크기를 설정
	virtual VOID SetScale(CONST Vector2& scale) override;

	// Scene을(를) 통해 상속됨
	VOID Initialize();
	VOID Release();
	VOID Update(const FLOAT& deltaTime);
	VOID Draw();
	BOOL Intersect_with_item(RECT item_rect);
};