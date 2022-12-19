#pragma once
#include "EngineMecro.h"
#include "Components/SpriteRenderer.h"
#include "Components/SpriteAnimation.h"
#include "Components/LRInput.h"
#include "UIManager.h"

using namespace ENGINE;

//�Լ��� ��ü�� ���
typedef std::function<void(int)> Item_effect;

class Bomb_effect : public GameObject
{
	//�������� ���� 
	//start_y �������� ���� ��ġ
	enum Bomb_Date { SpritesX = 8, SpritesY = 1 };
	float position_x, position_y;
	//�������� ���� ����
	bool isItem;
	//�������� ������ ���� ������ ���¿��� ������ ���� �پ� �ִ� ��ǥ


	//�÷��̾� �׸��� Ư�� �κи� �׷��ִ� Ŭ������ ����Ʈ������
	SpriteRenderer* bombrenderer;

	//�ִϸ��̼��� ����Ŭ������ ����Ʈ ������
	AnimationComponent* bombanim;

	RECT item_rect;

	Item_effect item_effect;
	Position position;
public:
	//�����ڿ��� ������ �� �ִ� �� (���� ����, ũ��)
	Bomb_effect();
	virtual VOID SetScale(CONST Vector2& scale) override;

	//�����ǿ� ���� ����
	VOID Update(const FLOAT& deltaTime, bool isbomb);
	VOID Draw();
	VOID GetPosition(Position position);
	RECT GetRect() { return item_rect; }

	void CollisionCheck(RECT rect)
	{
		item_effect(1);
	}
};

