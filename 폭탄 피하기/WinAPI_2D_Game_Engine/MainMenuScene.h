#pragma once

#include "EngineMecro.h"
#include "Components/LRInput.h"
#include "UIManager.h"

#ifndef MAIN_MENU_SCENE_H
#define MAIN_MENU_SCENE_H

namespace ENGINE
{
	class MainMenuScene : public Scene
	{
		BOOL isStart;
		FLOAT bounds, btn_height;

		HFONT font, oldfont;

		Bitmap* background = nullptr;

		UIButton* startBtn, * quitBtn;
		UIImage* menuWindow;

		UILabel* title;
	public:
		//Scene을 통해 상속
		virtual VOID Initialize() override;
		virtual VOID Release() override;
		virtual VOID Update(const FLOAT& deltaTime) override;
		virtual VOID Draw() override;

		VOID StartBtnClickHandler();
		VOID QuitBtnClickHandler();
	};
}


#endif // !MAIN_MENU_SCENE_H



//필요한것 타이틀, 시작버튼, 종료버튼
//필요한 변수. 시작체크할 bool
//타이틀 이름을 가지고 있을 string

//배경으로 사용할 Bitmap* background
//버튼을 조작할 UIButton* startBtn, *exitBtn
//윈도우 이미지 UIImage* MenuWindow		


//스프라이트 기능은 필요하지 않음
//연속된 그림이 여러게 그려져 있는 파일을 사용하지 않음