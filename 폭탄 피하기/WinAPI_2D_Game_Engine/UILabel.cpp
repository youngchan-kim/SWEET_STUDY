#include "UILabel.h"
#include "SceneManager.h"

namespace ENGINE
{
	// 사각형 설정
	VOID UILabel::SetRect(BOOL pivotCenter)
	{
		//폰트가 있다면 oldFont에 font를 SceneMgr->GetBackDC()에 적용하기 전(font가 NULL)을 리턴하여 대입연산한다.
		//GetBackDC에 font를 적용
		if (font) oldFont = (HFONT)SelectObject(SceneMgr->GetBackDC(), font);
		//문자열의 사각형의 사이즈를 알아와준다.
		GetTextExtentPoint32A(SceneMgr->GetBackDC(), text.c_str(), text.length(), &size);
		//폰트가 있다면 SceneMgr->GetBackDC()에 oldFont를 적용하기전(font를 적용한 상태)를 리턴한다.
		if (font) SelectObject(SceneMgr->GetBackDC(), oldFont);
		//포지션의 위치를 pos로 대입연산한다.
		POINT pos = position;
		// 기준점이 중심이면 0,0을 기준으로 그리는 것이 아니라
		if (pivotCenter)
		{
			// x축의 중심과 y축의 중심을 포지션에 뺄샘대입연산을 한다.
			pos.x -= size.cx * 0.5f;
			pos.y -= size.cy * 0.5f;
		}
		rect = { pos.x, pos.y, pos.x + size.cx, pos.y + size.cy };
	}

	//초기화
	VOID UILabel::Initialize(const std::string& text, COLORREF color, HFONT font)
	{
		//SetBkMode : 혼합 모드를 설정하는 함수 대상의 DC핸들과 플래그가 매개변수로 사용된다.
		//TRANSPARENT: 투명한 배경 색을 사용하여 문자를 출력시 문자의 배경이 변하지 않는다.
		SetBkMode(SceneMgr->GetBackDC(), TRANSPARENT);

		//글자의 색상
		SetColor(color);
		//글자 폰트
		SetFont(font);
		//글자
		SetText(text);
	}
	VOID UILabel::SetText(const std::string& text)
	{
		//text를 맴버 변수로 대입연산
		this->text = text;
		// 사각형 설정
		SetRect(pivotCenter);
	}
	VOID UILabel::SetFont(HFONT font)
	{
		//폰트가 있으면 
		if (font)
		{
			// 폰트를 맴버변수에 대입연산
			this->font = font;
			// text가 비어있지 않으면 사각형을 설정
			if (!text.empty())SetRect(pivotCenter);
		}
	}
	VOID UILabel::Draw()
	{
		// 사용불가
		if (!isEnable) return;
		//사용 가능
		//폰트가 있으면 이전 폰트를 저장하고 새로운 폰트를 적용
		if (font) oldFont = (HFONT)SelectObject(SceneMgr->GetBackDC(), font);
		//DC에 text의 색상을 설정
		SetTextColor(SceneMgr->GetBackDC(), color);
		//text를 사각형 안에 그린다.
		DrawTextA(SceneMgr->GetBackDC(), text.c_str(), text.length(), &rect, NULL);
		//폰트가 있다면 이전 폰트를 적용하여 사용한 폰트를 지운다.
		if (font) SelectObject(SceneMgr->GetBackDC(), oldFont);
		//UIPanel에 그림
		UIPanel::Draw();
	}
}//namespace ENGINE