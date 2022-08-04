#include "../Component.h"

#ifndef LR_INPUT_H
#define LR_INPUT_H

namespace ENGINE
{
	class LRInput : public InputComponent
	{
	public:
		enum class Direction { None = -1, Right = 0, Left = 1, };

	private:
		Direction dir;
		UINT left, right;

	public:
		LRInput() : dir(Direction::None), left(VK_LEFT), right(VK_RIGHT) {}

		VOID SetLeftKey(UINT left) { this->left = left; }
		VOID SetRightKey(UINT right) { this->right = right; }
		Direction GetDirection() CONST { return dir; }

		// InputComponent을(를) 통해 상속됨
		virtual VOID Operate(GameObject* Owner) override;
		virtual VOID Reset() override;
	};
}

#endif // !LR_INPUT_H