#include "../Component.h"

#ifndef SPRITE_ANIMATION_H
#define SPRITE_ANIMATION_H

namespace ENGINE
{
	class SpriteAnimation : public AnimationComponent
	{
	private:
		INT frame;
		FLOAT animTimer;
		Component* renderer;

	private:
		SpriteAnimation();
	public:
		SpriteAnimation(UINT divX = 1, UINT divY = 1, BOOL autoPlay = FALSE);

		// AnimationComponent��(��) ���� ��ӵ�
		virtual VOID Operate(GameObject* Owner) override;
		virtual VOID Reset() override;
	};
}

#endif // !SPRITE_ANIMATION_H