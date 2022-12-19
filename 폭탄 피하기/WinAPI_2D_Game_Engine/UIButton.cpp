#include "UIButton.h"
#include "ResourceManager.h"
#include "InputManager.h"

namespace ENGINE
{
	//�����ڿ��� ��ư ����
	ENGINE::UIButton::UIButton() :
		//clickListener �� �̺�Ʈ ����.
		//pressedListener �� �̺�Ʈ ����
		clickListener(nullptr), pressedListener(nullptr),
		//���� ����
		state(ButtonState::NONE),
		//Up �Ұ���
		//��ȣ�ۿ� ����
		isUp(FALSE), isInteractable(TRUE),
		//normal,pressed,hover,disable 
		normal(nullptr), pressed(nullptr), hover(nullptr), disable(nullptr)
	{
		//uitype�� ��ư
		uiType = UIType::BUTTON;
	}

	//�ʱ�ȭ
	VOID ENGINE::UIButton::Initialize(const std::string& normal, const std::string& pressed, const std::string& hover, const std::string& disable, DrawType type)
	{
		//UI�̹��� �̸��� Ÿ���� �ʱ�ȭ
		UIImage::Initialize(normal, type);

		//��Ʈ�ʵ��� ���� �̹����� �ּҸ� ������.
		this->disable = this->hover = this->pressed = this->normal = image;

		//�ش� ��Ʈ�� �����Ͱ� ������� ��� ��Ʈ���� �����´�.
		if (!pressed.empty()) this->pressed = ResourceMgr->GetBitmap(pressed);
		if (!hover.empty()) this->hover = ResourceMgr->GetBitmap(hover);
		if (!disable.empty()) this->disable = ResourceMgr->GetBitmap(disable);
	}

	//�̺�Ʈ tpye�� ����
	VOID ENGINE::UIButton::SetListener(EventListener click, EventListener pressed)
	{
		clickListener = click;
		pressedListener = pressed;
	}

	VOID ENGINE::UIButton::Update()
	{
		//��� �Ұ� �̸� ����
		if (!isEnable) return;
		//UI�̹����� ������Ʈ
		UIImage::Update();

		//��ȣ�ۿ��� �Ұ��� �ϴٸ�
		if (!isInteractable)
		{
			// ���´� ����
			state = ButtonState::NONE;
			//
			if (disable) image = disable;
			return;
		}

		//��ȣ�ۿ��� �����ϸ�
		//���콺 L��ư�� ���°� UP���� �ٲ�� �����ؼ� isUp�� �����Ѵ�.
		isUp = InputMgr->GetMouseButtonUp(VK_LBUTTON);

		//�гξȿ� ���콺 �������� ��ġ�Ѵٸ�
		if (PtInRect(&rect, InputMgr->GetMousePosition()))
		{
			// ��ư�� ���¿� ���� �۵��� �޶�����.
			switch (state)
			{
				//��ư�� ������ �ʾҴٸ� ���´� HOVER
			case ButtonState::NONE: state = ButtonState::HOVER;
				// ��ư�� ���°� HOVER�϶� ���콺 �� ��ư�� ���� ������ ���¸� PRESSED
			case ButtonState::HOVER: if (InputMgr->GetMouseButtonDown(VK_LBUTTON)) state = ButtonState::PRESSED; break;
				// ��ư�� ���°� PRESSED�϶� ��ư�� �ö���� Ŭ�������ʰ� �´ٸ�? Ŭ�������͸� ȣ��
			case ButtonState::PRESSED: if (isUp && clickListener) clickListener(); break;
			}
		}
		// ��ư�� ���°� PRESSED�� �ƴϸ� ���¸�  NONE�� �ٲ۴�. 
		else if (ButtonState::PRESSED != state) state = ButtonState::NONE;


		switch (state)
		{
			//�ش� ���¿� �´� ��Ʈ���� �ּҸ� �̹����� ���Կ����Ѵ�.  
		case ButtonState::NONE: image = normal; break;
		case ButtonState::HOVER: image = hover; break;
			//���°� PRESSED�϶� �̹����� Pressed�� ���Կ����Ѵ�.
			//���࿡ ��ư�� ���°� UP�̸� ���¿� NONE�� �����Ѵ�.
			//���࿡ pressedListener�� �´ٸ� pressedListener�� ȣ���Ѵ�.
		case ButtonState::PRESSED: image = pressed; if (isUp) state = ButtonState::NONE; if (pressedListener) pressedListener(); break;
		}
	}
}// namespace ENGINE