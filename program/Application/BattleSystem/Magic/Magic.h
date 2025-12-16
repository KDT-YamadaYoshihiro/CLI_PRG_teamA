#pragma once
#include <string>
#include <memory>
#include <vector>

#include <iostream>

#include "Application/BattleSystem/Target/TargetAttack.h"
#include "Application/BattleSystem/Magic/Manager/MagicManager.h"

namespace Magic 
{
	class MagicAction {

		MagicAction() = default;
		~MagicAction() = default;

	public:
		// UŒ‚‘ÎÛ‚ğ‘I‘ğ
		static void MagicAttack(Chara::Player* player, std::vector<Chara::Enemy*>enemylist,int index);
	};
}