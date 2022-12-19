#pragma once

#include "EngineMecro.h"
#include "Components/LRInput.h"
#include "UIManager.h"

#ifndef END_MENU_SCENE_H
#define END_MENU_SCENE_H

using namespace ENGINE;

class EndMenuScene
{
	BOOL isStart;

	Bitmap* background = nullptr;

	std::string board_name;
	//UIButton* retryBtn;
	UIImage* EndWindow;
	UILabel* board;
	UIButton* endquitBtn, * playBtn;
	UILabel* scoretitle;
	HFONT font;
	//너비
	float bounds;
	//버튼의 높이
	float btn_height;

	int score;
public:
	EndMenuScene();
;
	VOID Update();
	VOID Draw();

	VOID PlayBtnClickHandler();
	VOID QuitBtnClickHandler();
	VOID EndWindow_Enable_True();
	VOID Score(int end_score) 
	{ 
		score = end_score;
		score = end_score; 
	}
	bool restart() { return isStart;}
};

#endif
//필요한 것 게임중의 점수 