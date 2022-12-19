#pragma once
#include "EngineMecro.h"
#include "Components/SpriteRenderer.h"
#include "Components/SpriteAnimation.h"
#include "Components/LRInput.h"
#include "UIManager.h"

using namespace ENGINE;
//�÷��̾�� ���ӿ�����Ʈ Ŭ������ �� �������̽��� ��� �޴´�. // �� �������̽��� ��� ���� �ʾƵ� �ȴ�.
class Player : public GameObject
{
	//�÷��̾ ������ ���� // ��ġ �������� ����������
	enum Data { SpritesX = 4, SpritesY = 2, Speed = 200 };

	//�÷��̾� �׸��� Ư�� �κи� �׷��ִ� Ŭ������ ����Ʈ������
	SpriteRenderer* renderer;

	//�ִϸ��̼��� ����Ŭ������ ����Ʈ ������
	AnimationComponent* anim;

	//����Ű�� ������ ��� ����Ʈ����
	LRInput* input;

	RECT player_rect;
public:
	Player();
	

	// ũ�⸦ ����
	virtual VOID SetScale(CONST Vector2& scale) override;

	// Scene��(��) ���� ��ӵ�
	VOID Initialize();
	VOID Release();
	VOID Update(const FLOAT& deltaTime);
	VOID Draw();
	BOOL Intersect_with_item(RECT item_rect);
};