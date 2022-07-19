#include "LRInput.h"
#include "../InputManager.h"

namespace ENGINE
{
	VOID LRInput::Operate(GameObject* Owner)
	{
		if (ENGINE::InputMgr->GetKeyPressed(left))
		{
			dir = Direction::Left;
		}
		else if (ENGINE::InputMgr->GetKeyPressed(right))
		{
			dir = Direction::Right;
		}
		else dir = Direction::None;
	}

	VOID LRInput::Reset()
	{
		dir = Direction::None;
	}
}