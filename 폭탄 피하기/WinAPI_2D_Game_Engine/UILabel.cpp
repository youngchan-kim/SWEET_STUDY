#include "UILabel.h"
#include "SceneManager.h"

namespace ENGINE
{
	// �簢�� ����
	VOID UILabel::SetRect(BOOL pivotCenter)
	{
		//��Ʈ�� �ִٸ� oldFont�� font�� SceneMgr->GetBackDC()�� �����ϱ� ��(font�� NULL)�� �����Ͽ� ���Կ����Ѵ�.
		//GetBackDC�� font�� ����
		if (font) oldFont = (HFONT)SelectObject(SceneMgr->GetBackDC(), font);
		//���ڿ��� �簢���� ����� �˾ƿ��ش�.
		GetTextExtentPoint32A(SceneMgr->GetBackDC(), text.c_str(), text.length(), &size);
		//��Ʈ�� �ִٸ� SceneMgr->GetBackDC()�� oldFont�� �����ϱ���(font�� ������ ����)�� �����Ѵ�.
		if (font) SelectObject(SceneMgr->GetBackDC(), oldFont);
		//�������� ��ġ�� pos�� ���Կ����Ѵ�.
		POINT pos = position;
		// �������� �߽��̸� 0,0�� �������� �׸��� ���� �ƴ϶�
		if (pivotCenter)
		{
			// x���� �߽ɰ� y���� �߽��� �����ǿ� �������Կ����� �Ѵ�.
			pos.x -= size.cx * 0.5f;
			pos.y -= size.cy * 0.5f;
		}
		rect = { pos.x, pos.y, pos.x + size.cx, pos.y + size.cy };
	}

	//�ʱ�ȭ
	VOID UILabel::Initialize(const std::string& text, COLORREF color, HFONT font)
	{
		//SetBkMode : ȥ�� ��带 �����ϴ� �Լ� ����� DC�ڵ�� �÷��װ� �Ű������� ���ȴ�.
		//TRANSPARENT: ������ ��� ���� ����Ͽ� ���ڸ� ��½� ������ ����� ������ �ʴ´�.
		SetBkMode(SceneMgr->GetBackDC(), TRANSPARENT);

		//������ ����
		SetColor(color);
		//���� ��Ʈ
		SetFont(font);
		//����
		SetText(text);
	}
	VOID UILabel::SetText(const std::string& text)
	{
		//text�� �ɹ� ������ ���Կ���
		this->text = text;
		// �簢�� ����
		SetRect(pivotCenter);
	}
	VOID UILabel::SetFont(HFONT font)
	{
		//��Ʈ�� ������ 
		if (font)
		{
			// ��Ʈ�� �ɹ������� ���Կ���
			this->font = font;
			// text�� ������� ������ �簢���� ����
			if (!text.empty())SetRect(pivotCenter);
		}
	}
	VOID UILabel::Draw()
	{
		// ���Ұ�
		if (!isEnable) return;
		//��� ����
		//��Ʈ�� ������ ���� ��Ʈ�� �����ϰ� ���ο� ��Ʈ�� ����
		if (font) oldFont = (HFONT)SelectObject(SceneMgr->GetBackDC(), font);
		//DC�� text�� ������ ����
		SetTextColor(SceneMgr->GetBackDC(), color);
		//text�� �簢�� �ȿ� �׸���.
		DrawTextA(SceneMgr->GetBackDC(), text.c_str(), text.length(), &rect, NULL);
		//��Ʈ�� �ִٸ� ���� ��Ʈ�� �����Ͽ� ����� ��Ʈ�� �����.
		if (font) SelectObject(SceneMgr->GetBackDC(), oldFont);
		//UIPanel�� �׸�
		UIPanel::Draw();
	}
}//namespace ENGINE