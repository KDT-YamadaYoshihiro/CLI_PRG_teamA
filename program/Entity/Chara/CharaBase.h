#pragma once
#include <string>

struct CharaData
{
	std::string NAME;
	int HP;
	int MP;
	float ATK;
	float MAG;
	float DEF;
};

class CharaBase
{

protected:

	CharaData m_state;
	
public:

	CharaBase(const CharaData& data):m_state(data) 
	{
	}

	float GetAttack() 
	{
		return m_state.ATK;
	}

	float GetMagic() 
	{
		return m_state.MAG;
	}

	void Damage(float attackpoint) 
	{
		int damage = attackpoint / 2 - m_state.DEF / 4;
		m_state.HP - damage;
	}
};