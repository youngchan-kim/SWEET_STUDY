#pragma once
#include "EngineMecro.h"
#include "Components/SpriteRenderer.h"
#include "Components/SpriteAnimation.h"
#include "Components/LRInput.h"
#include "UIManager.h"

using namespace ENGINE;


typedef std::function<void(int)> Item_effect;


class DropItem : public GameObject
{
	//아이템의 영역 
	//start_y 아이템의 생성 위치
	enum Data { X = 1, Y = 1, start_y = 0 };
	//속도
	float speed = 100;
	//아이템의 존재 유무
	bool isItem;
	//아이템의 오른쪽 끝이 나오는 상태에서 오른쪽 끝에 붙어 있는 좌표


	//플레이어 그림중 특정 부분만 그려주는 클래스의 포인트변수명
	SpriteRenderer* itemrenderer;

	//애니메이션의 정보클래스의 포인트 변수명
	AnimationComponent* anim;

	RECT item_rect;

	Item_effect item_effect;

	//start_x
	float start_x, rand_y;
	float end_x;
	Position position;
public:
	//생성자에서 설정할 수 있는 것 (시작 높이, 크기)
	DropItem(Item_effect f, std::string name, std::string names = "");
	virtual VOID SetScale(CONST Vector2& scale) override;

	VOID Rand_Pos();
	VOID Position_Reset();
	//포지션에 대한 정보
	VOID Initialize();

	VOID Release();
	VOID Update(const FLOAT& deltaTime);
	VOID Draw();
	RECT GetRect() { return item_rect; }

	VOID Reset(bool isItem);

	Position Output_Position();


	void CollisionCheck(RECT rect)
	{
		item_effect(1);
	}
};

