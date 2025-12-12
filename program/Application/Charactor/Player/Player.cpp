#include"Application/Charactor/Player/Player.hpp"

Chara::Player::Player(const Chara::Status& Status)
	:CharaBase(Status)
{
}

/// <summary>
/// ˆÚ“®ˆ—
/// </summary>
/// <param name="Velocity">ˆÚ“®—Ê</param>
void Chara::Player::Move(const Math::Point& Velocity)
{
	m_position += Velocity;
}


