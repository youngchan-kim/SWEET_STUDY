#include "EngineMecro.h"
#include "Components/SpriteRenderer.h"
#include "Components/SpriteAnimation.h"
#include "Components/LRInput.h"
#include "UIManager.h"

#ifndef DEMO_SCENE_H
#define DEMO_SCENE_H

using namespace ENGINE;

class Player : public GameObject, public Scene
{
	enum Data { SpritesX = 4, SpritesY = 2, Speed = 200 };
	SpriteRenderer* renderer;
	AnimationComponent* anim;
	LRInput* input;
public:
	Player();

	// GameObject을(를) 통해 상속됨
	virtual VOID SetScale(CONST Vector2& scale) override;

	// Scene을(를) 통해 상속됨
	virtual VOID Initialize() override;
	virtual VOID Release() override;
	virtual VOID Update(const FLOAT& deltaTime) override;
	virtual VOID Draw() override;
};

class DemoScene : public Scene
{
	BOOL isPause;
	INT bounds;

	Bitmap* background = nullptr;
	Player* player = nullptr;
	Transform* playerTr = nullptr;
	SpriteRenderer* playerSr = nullptr;

	UIButton* pauseBtn;
	UIImage* pauseWindow;

public:
	// Scene을(를) 통해 상속됨
	virtual VOID Initialize() override;
	virtual VOID Release() override;
	virtual VOID Update(const FLOAT& deltaTime) override;
	virtual VOID Draw() override;

	VOID PauseBtnClickHandler();
	VOID ContinueBtnClickHandler();
	VOID QuitBtnClickHandler();
};

#endif // !DEMO_SCENE_H