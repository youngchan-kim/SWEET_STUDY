#pragma once
#include "EngineMecro.h"

#ifndef UI_PANEL_H
#define UI_PANEL_H
namespace ENGINE
{
	enum class UIType { PANEL, IMAGE, BUTTON, LABEL };
	class UIPanel
	{
	protected:
		BOOL isEnable, pivotCenter;
		POINT position, localPosition;
		RECT rect;
		SIZE size;
		UIPanel* parent;
		std::vector<UIPanel*> child;
		UIType uiType;

	public:
		UIPanel();
		virtual ~UIPanel();
	private:
		VOID SetParent(UIPanel* parent) { this->parent = parent; }
		VOID SetLocalPos(INT32 x, INT32 y);
	protected:
		//�簢���� �����簢���� ���� �Ѵ�.
		virtual VOID SetRect(BOOL pivotCenter) { rect = { localPosition.x, localPosition.y, localPosition.x, localPosition.y }; }
	public:
		virtual VOID SetPosition(INT32 x, INT32 y, BOOL pivotCenter = FALSE); // ����(��ũ��) ��ǥ ���� ��ġ.
		virtual VOID SetLocalPosition(INT32 x, INT32 y, BOOL pivotCenter = FALSE); // �θ� UI�� �������� �� ��ġ.
		virtual VOID Update();
		virtual VOID Draw();
		//�ڽ����� �߰��� ui�� �˾Ƽ� �޸𸮸� �����Ѵ�.

		UIPanel* AddChildUI(UIPanel* ui); //���� ����, �ڽ� UI�߰�.
		VOID RemoveChildUI(UIPanel* ui); //�ڽĿ��� �����ϰ� �޸� ������ ���� �ʴ´�.
		VOID RefreshPos(); // ����� �ڽ��� ��ġ�� �߽����� �ڽ� UI�� ��ġ�� ���ġ
		VOID SetEnable(BOOL enable) { isEnable = enable; }
		BOOL Enable() CONST { return isEnable; }
		UINT32 GetChildCount() CONST { return child.size(); }
		UIPanel* GetChild(INT32 index);
		UIPanel* GetParent() CONST { return parent; }
		POINT GetPosition()CONST { return position; }
		POINT GetLocalPosition() CONST { return localPosition; }
		UIType GetUIType() CONST { return uiType; }
		SIZE GetSize() CONST { return size; }
	}; // class UIPanel
}// namespace ENGINE
#endif // !UI_PANEL_H