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
		// ������ ���������� �̺�Ʈ�� �ޱ�����
		EventListener clickListener, pressedListener;
		// ��ư�� ����
		ButtonState state;
		// isUp : �ö� �ִ� �� ����
		// isInteractable : ��ȣ�ۿ� ����
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