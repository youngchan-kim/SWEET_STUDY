#include "EngineMecro.h"
#include "Components/SpriteRenderer.h"
#include "Components/SpriteAnimation.h"
#include "Components/LRInput.h"
#include "UIManager.h"
#include "Player.h"
#include "Dropitem.h"
#include "Bomb_effect.h"
#include "EndMenuScene.h"
#ifndef DEMO_SCENE_H
#define DEMO_SCENE_H

using namespace ENGINE;

class DemoScene : public Scene
{
	int score = 0;
	float timer = 0;
	BOOL isPause, isBomb;
	INT bounds;
	enum Data { ITEMNUM = 8, life_num = 5, SpritesX = 2, SpritesY = 1, life_size = 1 };
	Bitmap* background = nullptr;
	Player* player = nullptr;
	Transform* playerTr = nullptr;
	SpriteRenderer* playerSr = nullptr;

	std::string name = "", names = "";
	
	//DropItem* dropitem = nullptr;
	//Transform* dropitemTr = nullptr;
	//SpriteRenderer* dropitemSr = nullptr;

	
	//해당클래스들의 정보를 사용하기 위해 포인터를 사용하여 클래스의 주소를 불러온다.
	DropItem* dropitem[ITEMNUM];
	Transform* dropitemTr[ITEMNUM];
	SpriteRenderer* dropitemSr[ITEMNUM];


	Bomb_effect *bomb_effect = nullptr;
	Transform* bomb_effectTr = nullptr;
	SpriteRenderer* bomb_effectSr = nullptr;

	EndMenuScene* endmenuscene = nullptr;

	std::string board_name;
	UIButton* pauseBtn;
	UIImage* pauseWindow;
	UILabel* board;

	RECT item_rect;

	HFONT font;
	
	//UIImage* life_image;
	Bitmap* life_imageSr;
	SIZE drawSize;
	POINT life_draw_pos;
	int life;
	bool isDie;
	//reset시 초기화 해야할 값
private:
	//충돌 값을 가진 변수
	bool life_check[life_num];
	bool intersect = false;

public:
	// Scene을(를) 통해 상속됨
	virtual VOID Initialize() override;
	virtual VOID Release() override;
	virtual VOID Update(const FLOAT& deltaTime) override;
	virtual VOID Draw() override;

	VOID PauseBtnClickHandler();
	VOID ContinueBtnClickHandler();
	VOID QuitBtnClickHandler();
	VOID ReSet();
	//VOID Life_Decrease();

	void AddScore(int a);
	void Dec_Life(int a);


};

#endif // !DEMO_SCENE_H