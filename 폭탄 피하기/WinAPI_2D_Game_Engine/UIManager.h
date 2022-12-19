#pragma once
//해당씬에서 사용할 UI를 가지고, 사용되는 모든 UI를 갱신 및 그리기를 처리하여 준다.
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
		//초기화
		VOID Initialize();
		//지우기
		VOID Clear();
		//업데이트
		VOID Update();
		//그리기
		VOID Draw();

		//UI 추가 : UI의 이름과 패널의 상태에 부모패널이 없음
		template<typename T> T* AddUI(std::string name, UIPanel* parent = nullptr);
		//UI를 가져오기 : name와 같은 이름의 UI를 가져옴
		UIPanel* GetUI(std::string name);

		//UI 지우기 : name와 같은 이름의 UI를 지움
		BOOL Remove(std::string name);

		friend Singleton;
	}; // class UIManager

	//함수형 템플릿
	template<typename T>
	inline T* UIManager::AddUI(std::string name, UIPanel* parent)
	{
		//이름이 없다면 
		if (name.empty()) return nullptr; // 빈 문자열을 이름으로 지정할 수 없게 한다.
		auto iter = map_UI.find(name); // 이미 같은 이름의 UI가 있을 경우 추가 실패.
		if (map_UI.end() != iter) return nullptr; // 이미 있는 UI의 타입이 다를 수 있기에 null을 반환.

		//동적할당
		T* ui = new T;
		//부모가 있다면 부모의 AddChildUI를 사용하여 현재ui를 부모의 자식ui로 설정 
		if (parent) parent->AddChildUI(ui);

		//map_UI에 추가한다. name를 가진 ui를
		map_UI.insert(std::make_pair(name, ui));

		return ui;
	}
#define UIMgr UIManager::GetInstance()
}
#endif // !UI_MANAGER_H