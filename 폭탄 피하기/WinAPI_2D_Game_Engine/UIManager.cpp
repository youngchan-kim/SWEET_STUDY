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
		//map_UI�� ������ ���� pair�� ���� UIPanel�� ������ ����
		for (std::pair<std::string, UIPanel*> pair : map_UI) DEL(pair.second);
		//map_UI�� ������ ����
		map_UI.clear();
	}

	VOID UIManager::Update()
	{
		//Update�� ������ ȣ������ �ʱ� ����
		//�θ� ���� ��� �θ� �ʿ��� Update() �Լ��� ȣ�� �ϰ� �ִ�.
		for (std::pair<std::string, UIPanel*> pair : map_UI)
			if (!pair.second->GetParent())pair.second->Update();
	}

	VOID UIManager::Draw()
	{
		//�θ� ���� ��� �θ� �ʿ��� Draw() �Լ��� ȣ�� �ϰ� �ִ�.
		for (std::pair<std::string, UIPanel*> pair : map_UI)
			if (!pair.second->GetParent())pair.second->Draw();
	}

	UIPanel* UIManager::GetUI(std::string name)
	{
		//map_UI ���� name�� ���� �̸��� ���� ������ iter�� ����
		auto iter = map_UI.find(name);

		// iter�� ���� null�� �ƴϸ� iter�� panel�� �����Ѵ�.
		if (map_UI.end() != iter) return iter->second;

		return nullptr;
	}

	BOOL UIManager::Remove(std::string name)
	{
		// ���� ���� panel�� ui�� �����Ѵ�.
		auto ui = GetUI(name);
		// ui�� nullptr�� �ƴϸ� 
		if (nullptr != ui)
		{
			//�ش� name�� ���� ������ �����.
			map_UI.erase(name);
			//ui�� �����.
			DEL(ui);
			return TRUE;
		}
		return FALSE;
	}
} // namespace ENGINE
