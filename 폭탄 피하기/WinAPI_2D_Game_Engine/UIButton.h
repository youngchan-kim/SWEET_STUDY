#pragma once
#include "UIImage.h"
#ifndef UI_BUTTON_H
#define UI_BUTTON_H
namespace ENGINE
{
	class UIButton : public UIImage
	{
		enum class ButtonState { NONE, HOVER, PRESSED };
	protected:
		// 눌럿다 때었을때의 이벤트를 받기위함
		EventListener clickListener, pressedListener;
		// 버튼의 상태
		ButtonState state;
		// isUp : 올라가 있는 지 유무
		// isInteractable : 상호작용 유무
		BOOL isUp, isInteractable;

		Bitmap* normal, * pressed, * hover, * disable;

	public:
		UIButton();

		VOID Initialize(CONST std::string& normal, CONST std::string& pressed = "", CONST std::string& hover = "", CONST std::string& disable = "", DrawType type = DrawType::Normal);
		VOID SetListener(EventListener click, EventListener pressed = nullptr);
		VOID SetInteracterble(BOOL interactable) { isInteractable = interactable; }
		BOOL IsInteracterble() CONST { return isInteractable; }
		virtual VOID Update() override;
	};
}//namespace ENGINE
#endif // !UI_BUTTON_H