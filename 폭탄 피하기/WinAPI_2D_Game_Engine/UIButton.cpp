#include "UIButton.h"
#include "ResourceManager.h"
#include "InputManager.h"

namespace ENGINE
{
	//생성자에서 버튼 설정
	ENGINE::UIButton::UIButton() :
		//clickListener 시 이벤트 없음.
		//pressedListener 시 이벤트 없음
		clickListener(nullptr), pressedListener(nullptr),
		//상태 없음
		state(ButtonState::NONE),
		//Up 불가능
		//상호작용 가능
		isUp(FALSE), isInteractable(TRUE),
		//normal,pressed,hover,disable 
		normal(nullptr), pressed(nullptr), hover(nullptr), disable(nullptr)
	{
		//uitype은 버튼
		uiType = UIType::BUTTON;
	}

	//초기화
	VOID ENGINE::UIButton::Initialize(const std::string& normal, const std::string& pressed, const std::string& hover, const std::string& disable, DrawType type)
	{
		//UI이미지 이름과 타입을 초기화
		UIImage::Initialize(normal, type);

		//비트맵들은 같은 이미지의 주소를 가진다.
		this->disable = this->hover = this->pressed = this->normal = image;

		//해당 비트맵 포인터가 비어있을 경우 비트맵을 가져온다.
		if (!pressed.empty()) this->pressed = ResourceMgr->GetBitmap(pressed);
		if (!hover.empty()) this->hover = ResourceMgr->GetBitmap(hover);
		if (!disable.empty()) this->disable = ResourceMgr->GetBitmap(disable);
	}

	//이벤트 tpye을 설정
	VOID ENGINE::UIButton::SetListener(EventListener click, EventListener pressed)
	{
		clickListener = click;
		pressedListener = pressed;
	}

	VOID ENGINE::UIButton::Update()
	{
		//사용 불가 이면 리턴
		if (!isEnable) return;
		//UI이미지를 업데이트
		UIImage::Update();

		//상호작용이 불가능 하다면
		if (!isInteractable)
		{
			// 상태는 없음
			state = ButtonState::NONE;
			//
			if (disable) image = disable;
			return;
		}

		//상호작용이 가능하면
		//마우스 L버튼의 상태가 UP으로 바뀌면 리턴해서 isUp에 대입한다.
		isUp = InputMgr->GetMouseButtonUp(VK_LBUTTON);

		//패널안에 마우스 포인터의 위치한다면
		if (PtInRect(&rect, InputMgr->GetMousePosition()))
		{
			// 버튼의 상태에 따라 작동이 달라진다.
			switch (state)
			{
				//버튼이 눌리지 않았다면 상태는 HOVER
			case ButtonState::NONE: state = ButtonState::HOVER;
				// 버튼의 상태가 HOVER일때 마우스 왼 버튼이 눌려 있을때 상태를 PRESSED
			case ButtonState::HOVER: if (InputMgr->GetMouseButtonDown(VK_LBUTTON)) state = ButtonState::PRESSED; break;
				// 버튼의 상태가 PRESSED일때 버튼이 올라오고 클릭리스너가 맞다면? 클릭리스터를 호출
			case ButtonState::PRESSED: if (isUp && clickListener) clickListener(); break;
			}
		}
		// 버튼의 상태가 PRESSED가 아니면 상태를  NONE로 바꾼다. 
		else if (ButtonState::PRESSED != state) state = ButtonState::NONE;


		switch (state)
		{
			//해당 상태에 맞는 비트맵의 주소를 이미지에 대입연산한다.  
		case ButtonState::NONE: image = normal; break;
		case ButtonState::HOVER: image = hover; break;
			//상태가 PRESSED일때 이미지에 Pressed를 대입연산한다.
			//만약에 버튼의 상태가 UP이면 상태에 NONE를 대입한다.
			//만약에 pressedListener가 맞다면 pressedListener를 호출한다.
		case ButtonState::PRESSED: image = pressed; if (isUp) state = ButtonState::NONE; if (pressedListener) pressedListener(); break;
		}
	}
}// namespace ENGINE