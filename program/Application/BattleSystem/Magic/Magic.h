#pragma once
#include <string>
#include <memory>
#include <vector>

#include <iostream>

#include "../Target/TargetAttack.h"
using namespace Chara;
#include "Manager/Manager.h"
using namespace Magic;

namespace Magic 
{
	class MagicAction {

		MagicAction() = default;
		~MagicAction() = default;

	public:

		// UŒ‚‘ÎÛ‚ğ‘I‘ğ
		static void MagicAttack(Player* player, std::vector<Enemy*>enemylist,int index);

	};
}