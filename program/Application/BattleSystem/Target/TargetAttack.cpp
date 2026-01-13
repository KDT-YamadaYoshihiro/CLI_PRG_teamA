#include "TargetAttack.h"
#include "Application/Charactor/Player/Player.hpp"
#include "Application/Charactor/Enemy/Enemy.h"
#include"Application/BattleSystem/action/Calc/BattleCalc.hpp"
#include "Engine/Engine.hpp"
#include "Application/Inventory/Inventory/InventoryManager.hpp"

void Battle::Action::Attack(Chara::Player* player, std::vector<Chara::Enemy*> enemyList)
{
	// cinを使用して入力
	int number = enemyList.size();

	if (enemyList.size() > 1)
	{
		std::string count = std::to_string(enemyList.size() - 1);
		// 対象の選択案内
		CLI_ENGINE->GetView()->AddLine("対象を０から" + count + "の中から選んでください");
		CLI_ENGINE->GetView()->Render();
		std::cin >> number;
		// 選択範囲内になるまでループ
		while (number >= enemyList.size())
		{
			// 対象の選択案内
			//CLI_ENGINE->GetView()->AddLine("選択範囲外です。もう一度入力してください");
			std::cout << "選択範囲外です。もう一度入力してください" << std::endl;
			//CLI_ENGINE->GetTimer()->Sleep(std::chrono::milliseconds(500));
			std::cin >> number;
		}
	}
	else
	{
		number = 0;
	}


    // ダメージ計算
	int damage = Battle::BattleCalc::CalcDamage(player->GetAttack(),enemyList[number]->GetDefence());
	// 計算値を対象に与える。
	enemyList[number]->ApplyDamage(damage);
	// 表示用ダメージ値を作成
	std::string log_damage = std::to_string(damage);
	// ログを出す
	CLI_ENGINE->GetView()->AddLine("\n" + player->GetName() + "は" + enemyList[number]->GetName() + "に" + log_damage + "を与えた。");
	CLI_ENGINE->GetView()->Render();
	CLI_ENGINE->GetTimer()->Sleep(std::chrono::milliseconds(500));

}

void Battle::Action::ItemUse(Chara::Player* player, Inventory::InventoryManager* inventoryManager, int use_number)
{
	// ログを出す
	CLI_ENGINE->GetView()->AddLine("\n" + player->GetName() + "は" + inventoryManager->GetAllNames()[use_number] + "を使用した。");
	CLI_ENGINE->GetView()->Render();
	CLI_ENGINE->GetTimer()->Sleep(std::chrono::milliseconds(500));

	// 選択アイテムを使用
	inventoryManager->UseItem(use_number, player);

}
