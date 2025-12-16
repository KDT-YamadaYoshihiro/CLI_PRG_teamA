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

namespace Inventory
{
	class InventoryManager;
}

namespace Battle {

	class Action
	{
		
		Action() = default;
		~Action() = default;
	public:
		// プレイヤーがエネミーの攻撃対象を選択
		static void Attack(Chara::Player* plyaer, std::vector<Chara::Enemy*> enemyList);
		// プレイヤーがアイテムを選択
		static void ItemUse(Chara::Player* player, Inventory::InventoryManager* inventoryManager, int use_number);
	};
}

