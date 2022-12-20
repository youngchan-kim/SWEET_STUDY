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
		//Scene�� ���� ���
		virtual VOID Initialize() override;
		virtual VOID Release() override;
		virtual VOID Update(const FLOAT& deltaTime) override;
		virtual VOID Draw() override;

		VOID StartBtnClickHandler();
		VOID QuitBtnClickHandler();
	};
}


#endif // !MAIN_MENU_SCENE_H



//�ʿ��Ѱ� Ÿ��Ʋ, ���۹�ư, �����ư
//�ʿ��� ����. ����üũ�� bool
//Ÿ��Ʋ �̸��� ������ ���� string

//������� ����� Bitmap* background
//��ư�� ������ UIButton* startBtn, *exitBtn
//������ �̹��� UIImage* MenuWindow		


//��������Ʈ ����� �ʿ����� ����
//���ӵ� �׸��� ������ �׷��� �ִ� ������ ������� ����