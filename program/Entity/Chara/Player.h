#pragma once
#include "CharaBase.h"
#include "../../../program/System/math/Vec2.h"
#include "../../../program/System/Input/Input.h"

class PlayerChara : public CharaBase 
{
private:

	Postition m_pos;

public:

	void SetPostition() {
	
		if (ConsoleInput::GetChar() == 'w') {
			m_pos.m_postition_y -= 1;
		}
	
		if (ConsoleInput::GetChar() == 's') {
			m_pos.m_postition_y += 1;
		}

		if (ConsoleInput::GetChar() == 'a') {
			m_pos.m_postition_x -= 1;
		}

		if (ConsoleInput::GetChar() == 'd') {
			m_pos.m_postition_x += 1;
		}
	}

};