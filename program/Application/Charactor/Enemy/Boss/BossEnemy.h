#pragma once
#include "Application/Charactor/base/CharactorBase.hpp"

namespace Chara
{
	class BossEnemy : public Chara::CharaBase
	{

	public:
		//	‰Šú‰»
		BossEnemy(const Chara::Status& Status)
			:Chara::CharaBase(Status) {}
		virtual ~BossEnemy() = default;

		// ’ÊíUŒ‚
		void Attack(Chara::CharaBase& target);
		// ‰Š‚Ì‘§
		void FireBreath(Chara::CharaBase& target);

	};

}