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
	//�������� ���� 
	//start_y �������� ���� ��ġ
	enum Data { X = 1, Y = 1, start_y = 0 };
	//�ӵ�
	float speed = 100;
	//�������� ���� ����
	bool isItem;
	//�������� ������ ���� ������ ���¿��� ������ ���� �پ� �ִ� ��ǥ


	//�÷��̾� �׸��� Ư�� �κи� �׷��ִ� Ŭ������ ����Ʈ������
	SpriteRenderer* itemrenderer;

	//�ִϸ��̼��� ����Ŭ������ ����Ʈ ������
	AnimationComponent* anim;

	RECT item_rect;

	Item_effect item_effect;

	//start_x
	float start_x, rand_y;
	float end_x;
	Position position;
public:
	//�����ڿ��� ������ �� �ִ� �� (���� ����, ũ��)
	DropItem(Item_effect f, std::string name, std::string names = "");
	virtual VOID SetScale(CONST Vector2& scale) override;

	VOID Rand_Pos();
	VOID Position_Reset();
	//�����ǿ� ���� ����
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

