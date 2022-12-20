#include "UIManager.h"

namespace ENGINE
{
	UIManager::~UIManager()
	{
		Clear();
	}

	VOID UIManager::Initialize()
	{
		Clear();
	}

	VOID UIManager::Clear()
	{
		//map_UI의 정보를 전부 pair에 복사 UIPanel의 정보를 삭제
		for (std::pair<std::string, UIPanel*> pair : map_UI) DEL(pair.second);
		//map_UI의 정보를 삭제
		map_UI.clear();
	}

	VOID UIManager::Update()
	{
		//Update를 여러번 호출하지 않기 위함
		//부모가 있을 경우 부모 쪽에서 Update() 함수를 호출 하고 있다.
		for (std::pair<std::string, UIPanel*> pair : map_UI)
			if (!pair.second->GetParent())pair.second->Update();
	}

	VOID UIManager::Draw()
	{
		//부모가 있을 경우 부모 쪽에서 Draw() 함수를 호출 하고 있다.
		for (std::pair<std::string, UIPanel*> pair : map_UI)
			if (!pair.second->GetParent())pair.second->Draw();
	}

	UIPanel* UIManager::GetUI(std::string name)
	{
		//map_UI 에서 name와 같은 이름을 가진 정보를 iter에 대입
		auto iter = map_UI.find(name);

		// iter의 값이 null이 아니면 iter의 panel을 리턴한다.
		if (map_UI.end() != iter) return iter->second;

		return nullptr;
	}

	BOOL UIManager::Remove(std::string name)
	{
		// 리턴 받은 panel은 ui에 대입한다.
		auto ui = GetUI(name);
		// ui가 nullptr이 아니면 
		if (nullptr != ui)
		{
			//해당 name를 가진 정보를 지운다.
			map_UI.erase(name);
			//ui도 지운다.
			DEL(ui);
			return TRUE;
		}
		return FALSE;
	}
} // namespace ENGINE
