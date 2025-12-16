#pragma once
#include <string>
#include <memory>
#include <vector>

#include <iostream>

namespace Chara
{
	class Player;
	class Enemy;
}

namespace Battle {

	class Action
	{
		
		Action() = default;
		~Action() = default;
	public:
		// プレイヤーがエネミーの攻撃対象を選択
		static void Attack(Chara::Player* plyaer, std::vector<Chara::Enemy*> enemyList);
	};
}

