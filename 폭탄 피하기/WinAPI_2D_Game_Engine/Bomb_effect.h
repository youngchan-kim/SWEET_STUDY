#pragma once
#include "EngineMecro.h"
#include "Components/SpriteRenderer.h"
#include "Components/SpriteAnimation.h"
#include "Components/LRInput.h"
#include "UIManager.h"

using namespace ENGINE;

//함수를 객체로 사용
typedef std::function<void(int)> Item_effect;

class Bomb_effect : public GameObject
{
	//아이템의 영역 
	//start_y 아이템의 생성 위치
	enum Bomb_Date { SpritesX = 8, SpritesY = 1 };
	float position_x, position_y;
	//아이템의 존재 유무
	bool isItem;
	//아이템의 오른쪽 끝이 나오는 상태에서 오른쪽 끝에 붙어 있는 좌표


	//플레이어 그림중 특정 부분만 그려주는 클래스의 포인트변수명
	SpriteRenderer* bombrenderer;

	//애니메이션의 정보클래스의 포인트 변수명
	AnimationComponent* bombanim;

	RECT item_rect;

	Item_effect item_effect;
	Position position;
public:
	//생성자에서 설정할 수 있는 것 (시작 높이, 크기)
	Bomb_effect();
	virtual VOID SetScale(CONST Vector2& scale) override;

	//포지션에 대한 정보
	VOID Update(const FLOAT& deltaTime, bool isbomb);
	VOID Draw();
	VOID GetPosition(Position position);
	RECT GetRect() { return item_rect; }

	void CollisionCheck(RECT rect)
	{
		item_effect(1);
	}
};

