#pragma once
#include "UIPanel.h"
#include "SceneManager.h"
#include "Bitmap.h"
#ifndef UI_IMAGE_H
#define UI_IMAGE_H

namespace ENGINE
{
	enum class DrawType{Normal, Transparent};

	class UIImage : public UIPanel
	{
	protected:
		Bitmap* image;
		DrawType type;

	public:
		UIImage() : image(nullptr), type(DrawType::Normal) { uiType = UIType::IMAGE; }
		VOID Initialize(CONST std::string& ImageName, DrawType type = DrawType::Normal);
		virtual VOID Draw() override;

	protected:
		virtual VOID SetRect(BOOL pivotCenter) override;
	};
}
#endif // !UI_IMAGE_H