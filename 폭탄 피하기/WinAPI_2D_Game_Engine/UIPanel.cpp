#include "UIPanel.h"
namespace ENGINE
{
	//UIPanel의 생성자에서 속성을 설정
	UIPanel::UIPanel() :
		//사용이 가능하게 한다. 
		isEnable(TRUE), pivotCenter(FALSE), 
		//위치와, 지역 위치?
		// 포지션 : 실제 월드 상의 포지션
		// 로컬 포지션 : 부모를 중심으로한 포지션
		position({0, 0}), localPosition({0, 0}),
		//사각형의 위치와 크기, 패널의 사이즈
		rect({0, 0, 0, 0}), size({0, 0}),
		//부모는 없고 타입은 패널이다.
		parent(nullptr)	{uiType = UIType::PANEL;}

	//UIPanel의 소멸자가 호출되면 자식을 클리어한다.
	UIPanel::~UIPanel() { child.clear(); }

	//지역 위치의 초기화 (지역 위치는 부모 패널에 속해 있는 자식 패널들의 위치인가?)
	VOID UIPanel::SetLocalPos(INT32 x, INT32 y)
	{
		//(위치와 지역 위치를 x,y로 한다.)
		position = localPosition = { x, y };
		//부모 패널이 있으면 포지션의 x는 x+ 부모패널의 사각형의 left y는 y+부모패널의 사각형의 top이다. 
		if (parent) position = { x + parent->rect.left, y + parent->rect.top };
		//사각형 초기화 (기준점의 중심이 있을때)
		SetRect(pivotCenter);
		// 자식 패널 전부를 ui 포인터에 복사 한후 ui를 부모 포지션을 중점으로 새로 만든다. 
		for (UIPanel* ui : child) ui->RefreshPos();
	}

	//위치 초기화 : 기준점을 맴버변수에 대입
	VOID UIPanel::SetPosition(INT32 x, INT32 y, BOOL pivotCenter)
	{
		//기준점을 맴버변수에 대입연산한다.
		this->pivotCenter = pivotCenter;
		// 부모패널이 있으면 x-부모패널의 사각형의left , y - 부모패널의 사각형의 top 
		if (parent) SetLocalPos(x - parent->rect.left, y - parent->rect.top);
		//부모 패널이 없으면 x,y그대로 지역 위치 초기화
		else SetLocalPos(x, y);
	}
	//지역 위치 설정
	VOID UIPanel::SetLocalPosition(INT32 x, INT32 y, BOOL pivotCenter)
	{
		// 기준점을 맴버 변수에 대입연산.
		this->pivotCenter = pivotCenter;
		SetLocalPos(x, y);
	}

	//업데이트
	VOID UIPanel::Update()
	{
		//사용불가 이면 return으로 사용하지 않는다.
		if (!isEnable) return;
		//사용가능 이면 child의 ui패널도 업데이트한다.
		for (UIPanel* ui : child) ui->Update();
	}

	VOID UIPanel::Draw()
	{
		if (!isEnable) return;
		//사용가능 이면 child의 ui패널도 그린다.
		for (UIPanel* ui : child) ui->Draw();
	}

	//자식 ui를 추가한다.
	UIPanel* UIPanel::AddChildUI(UIPanel* ui)
	{
		//ui가 없다면 nullptr를 리턴한다.//포인터가 비어있음
		if (!ui) return nullptr;
		//child의 vector의 마지막에 ui를 추가한다.
		child.push_back(ui);
		//ui의 정보중 부모 부분에 현재 ui를 부모로 설정한다.
		ui->SetParent(this);
		
		//중복 제거.
		//  1 2 3 4 5 4 7 3
		//자식의 vector을 처음 부터 끝까지 정렬한다.
		// 1 2 3 3 4 4 5 7
		std::sort(child.begin(), child.end());
		//unique로 중복된 원소를 뒤로 넘긴다.(중복된 원소는 쓰레기 값이 되는건가?)
		//erase로 쓰래기 값을 제거한다.
		// std::unique(child.begin(), child.end()) 리턴 해주는 값은 중복된 값의 첫번 째 iter
		// 1 2 3 4 5 7 3 4
		//child.erase(std::unique(), child.end());
		child.erase(std::unique(child.begin(), child.end()), child.end());
		//ui를 리턴
		return ui;
	}

	// 자식 ui를 지운다.
	VOID UIPanel::RemoveChildUI(UIPanel* ui)
	{
		//ui가 없다면 실행하지 않는다.
		if (!ui) return;
		//iter에  자식 의 처음부터 null값까지 ui를 찾아 대입한다.
		std::vector<UIPanel*>::iterator iter = std::find(child.begin(), child.end(), ui);
		//iter의 값이 null일때 까지 실행한다.
		if (child.end() != iter)
		{
			//자식 패널중 iter의 정보를 가진 패널을 지움
			child.erase(iter);
			//iter의 주소에서 부모의 정보를 nullptr로 초기화해준다. 
			(*iter)->SetParent(nullptr);
		}
	}
	//위치를 재설정한다.
	VOID UIPanel::RefreshPos()
	{
		SetLocalPos(localPosition.x, localPosition.y);
	}
	// index번째 자식 패널을 가져온다.
	UIPanel* UIPanel::GetChild(INT32 index)
	{
		//index의 값이 정보다 작거나 자식 패널의 사이즈가 index보다 작거나 같으면 nullptr을 리턴
		if (0 > index || child.size() <= index) return nullptr;
		//자식패널중 index번째 자식을 리턴한다.
		return child[index];
	}
}//namespace EGINE
