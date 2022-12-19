#pragma once
//�ش������ ����� UI�� ������, ���Ǵ� ��� UI�� ���� �� �׸��⸦ ó���Ͽ� �ش�.
#include "Singleton.h"
#include "UIButton.h" //#include "UIImage.h"
#include "UILabel.h"  //#include "UIPanel.h"

#ifndef UI_MANAGER_H
#define UI_MANAGER_H

namespace ENGINE
{
	class UIManager : public Singleton<UIManager>
	{
	private:
		std::map<std::string, UIPanel*>map_UI;
		std::vector<UIPanel*> child_UI;

		UIManager() {}
	public:
		~UIManager();
		//�ʱ�ȭ
		VOID Initialize();
		//�����
		VOID Clear();
		//������Ʈ
		VOID Update();
		//�׸���
		VOID Draw();

		//UI �߰� : UI�� �̸��� �г��� ���¿� �θ��г��� ����
		template<typename T> T* AddUI(std::string name, UIPanel* parent = nullptr);
		//UI�� �������� : name�� ���� �̸��� UI�� ������
		UIPanel* GetUI(std::string name);

		//UI ����� : name�� ���� �̸��� UI�� ����
		BOOL Remove(std::string name);

		friend Singleton;
	}; // class UIManager

	//�Լ��� ���ø�
	template<typename T>
	inline T* UIManager::AddUI(std::string name, UIPanel* parent)
	{
		//�̸��� ���ٸ� 
		if (name.empty()) return nullptr; // �� ���ڿ��� �̸����� ������ �� ���� �Ѵ�.
		auto iter = map_UI.find(name); // �̹� ���� �̸��� UI�� ���� ��� �߰� ����.
		if (map_UI.end() != iter) return nullptr; // �̹� �ִ� UI�� Ÿ���� �ٸ� �� �ֱ⿡ null�� ��ȯ.

		//�����Ҵ�
		T* ui = new T;
		//�θ� �ִٸ� �θ��� AddChildUI�� ����Ͽ� ����ui�� �θ��� �ڽ�ui�� ���� 
		if (parent) parent->AddChildUI(ui);

		//map_UI�� �߰��Ѵ�. name�� ���� ui��
		map_UI.insert(std::make_pair(name, ui));

		return ui;
	}
#define UIMgr UIManager::GetInstance()
}
#endif // !UI_MANAGER_H