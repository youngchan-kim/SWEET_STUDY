#include "../Component.h"
#include "../Bitmap.h"

#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

namespace ENGINE
{
	//그래픽 컴포넌트를 상속 받음
	class SpriteRenderer : public GrahpicComponent
	{
	private:
		// 
		Bitmap* sprites;
		SIZE localSize, size;
		Vector2 pos, divide;

	private:
		SpriteRenderer();
	public:
		SpriteRenderer(LPCSTR name, UINT divX = 1, UINT divY = 1);

		VOID SetPivot(INT pivot) { if (sprites) sprites->SetPivot(pivot); }
		VOID SetSrc(UINT cx, UINT cy);
		SIZE GetDrawSize() { return size; }

		// GrahpicComponent을(를) 통해 상속됨
		virtual VOID Operate(GameObject* Owner) override;
		virtual VOID Reset() override;
		virtual VOID SetScale(UINT cx, UINT cy) override;
		virtual VOID Draw() override;
	};
}

#endif // !SPRITE_RENDERER_H

//스프라이트 플레이어의 동작 전부를 그려 놓은 그림을 나누어서 사용 할 수 있게 해줌