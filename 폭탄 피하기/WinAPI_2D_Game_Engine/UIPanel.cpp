#include "UIPanel.h"
namespace ENGINE
{
	//UIPanel�� �����ڿ��� �Ӽ��� ����
	UIPanel::UIPanel() :
		//����� �����ϰ� �Ѵ�. 
		isEnable(TRUE), pivotCenter(FALSE), 
		//��ġ��, ���� ��ġ?
		// ������ : ���� ���� ���� ������
		// ���� ������ : �θ� �߽������� ������
		position({0, 0}), localPosition({0, 0}),
		//�簢���� ��ġ�� ũ��, �г��� ������
		rect({0, 0, 0, 0}), size({0, 0}),
		//�θ�� ���� Ÿ���� �г��̴�.
		parent(nullptr)	{uiType = UIType::PANEL;}

	//UIPanel�� �Ҹ��ڰ� ȣ��Ǹ� �ڽ��� Ŭ�����Ѵ�.
	UIPanel::~UIPanel() { child.clear(); }

	//���� ��ġ�� �ʱ�ȭ (���� ��ġ�� �θ� �гο� ���� �ִ� �ڽ� �гε��� ��ġ�ΰ�?)
	VOID UIPanel::SetLocalPos(INT32 x, INT32 y)
	{
		//(��ġ�� ���� ��ġ�� x,y�� �Ѵ�.)
		position = localPosition = { x, y };
		//�θ� �г��� ������ �������� x�� x+ �θ��г��� �簢���� left y�� y+�θ��г��� �簢���� top�̴�. 
		if (parent) position = { x + parent->rect.left, y + parent->rect.top };
		//�簢�� �ʱ�ȭ (�������� �߽��� ������)
		SetRect(pivotCenter);
		// �ڽ� �г� ���θ� ui �����Ϳ� ���� ���� ui�� �θ� �������� �������� ���� �����. 
		for (UIPanel* ui : child) ui->RefreshPos();
	}

	//��ġ �ʱ�ȭ : �������� �ɹ������� ����
	VOID UIPanel::SetPosition(INT32 x, INT32 y, BOOL pivotCenter)
	{
		//�������� �ɹ������� ���Կ����Ѵ�.
		this->pivotCenter = pivotCenter;
		// �θ��г��� ������ x-�θ��г��� �簢����left , y - �θ��г��� �簢���� top 
		if (parent) SetLocalPos(x - parent->rect.left, y - parent->rect.top);
		//�θ� �г��� ������ x,y�״�� ���� ��ġ �ʱ�ȭ
		else SetLocalPos(x, y);
	}
	//���� ��ġ ����
	VOID UIPanel::SetLocalPosition(INT32 x, INT32 y, BOOL pivotCenter)
	{
		// �������� �ɹ� ������ ���Կ���.
		this->pivotCenter = pivotCenter;
		SetLocalPos(x, y);
	}

	//������Ʈ
	VOID UIPanel::Update()
	{
		//���Ұ� �̸� return���� ������� �ʴ´�.
		if (!isEnable) return;
		//��밡�� �̸� child�� ui�гε� ������Ʈ�Ѵ�.
		for (UIPanel* ui : child) ui->Update();
	}

	VOID UIPanel::Draw()
	{
		if (!isEnable) return;
		//��밡�� �̸� child�� ui�гε� �׸���.
		for (UIPanel* ui : child) ui->Draw();
	}

	//�ڽ� ui�� �߰��Ѵ�.
	UIPanel* UIPanel::AddChildUI(UIPanel* ui)
	{
		//ui�� ���ٸ� nullptr�� �����Ѵ�.//�����Ͱ� �������
		if (!ui) return nullptr;
		//child�� vector�� �������� ui�� �߰��Ѵ�.
		child.push_back(ui);
		//ui�� ������ �θ� �κп� ���� ui�� �θ�� �����Ѵ�.
		ui->SetParent(this);
		
		//�ߺ� ����.
		//  1 2 3 4 5 4 7 3
		//�ڽ��� vector�� ó�� ���� ������ �����Ѵ�.
		// 1 2 3 3 4 4 5 7
		std::sort(child.begin(), child.end());
		//unique�� �ߺ��� ���Ҹ� �ڷ� �ѱ��.(�ߺ��� ���Ҵ� ������ ���� �Ǵ°ǰ�?)
		//erase�� ������ ���� �����Ѵ�.
		// std::unique(child.begin(), child.end()) ���� ���ִ� ���� �ߺ��� ���� ù�� ° iter
		// 1 2 3 4 5 7 3 4
		//child.erase(std::unique(), child.end());
		child.erase(std::unique(child.begin(), child.end()), child.end());
		//ui�� ����
		return ui;
	}

	// �ڽ� ui�� �����.
	VOID UIPanel::RemoveChildUI(UIPanel* ui)
	{
		//ui�� ���ٸ� �������� �ʴ´�.
		if (!ui) return;
		//iter��  �ڽ� �� ó������ null������ ui�� ã�� �����Ѵ�.
		std::vector<UIPanel*>::iterator iter = std::find(child.begin(), child.end(), ui);
		//iter�� ���� null�϶� ���� �����Ѵ�.
		if (child.end() != iter)
		{
			//�ڽ� �г��� iter�� ������ ���� �г��� ����
			child.erase(iter);
			//iter�� �ּҿ��� �θ��� ������ nullptr�� �ʱ�ȭ���ش�. 
			(*iter)->SetParent(nullptr);
		}
	}
	//��ġ�� �缳���Ѵ�.
	VOID UIPanel::RefreshPos()
	{
		SetLocalPos(localPosition.x, localPosition.y);
	}
	// index��° �ڽ� �г��� �����´�.
	UIPanel* UIPanel::GetChild(INT32 index)
	{
		//index�� ���� ������ �۰ų� �ڽ� �г��� ����� index���� �۰ų� ������ nullptr�� ����
		if (0 > index || child.size() <= index) return nullptr;
		//�ڽ��г��� index��° �ڽ��� �����Ѵ�.
		return child[index];
	}
}//namespace EGINE
