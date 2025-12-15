#include "TargetAttack.h"
#include "Application/Charactor/Player/Player.hpp"
#include "Application/Charactor/Enemy/Enemy.h"
#include "Application/BattleSystem/Calc/BattleCalc.hpp"
#include "Engine/Engine.hpp"

void Battle::Action::Attack(Chara::Player* player, std::vector<Chara::Enemy> enemyList)
{
	std::string count = std::to_string(enemyList.size());
	// 対象の選択案内
	CLI_ENGINE->GetView()->AddLine("対象を０から" + count + "の中から選んでください");

	// cinを使用して入力
	int number = enemyList.size();
	// 選択範囲内になるまでループ
	while (number >= enemyList.size())
	{
		std::cin >> number;
		// 対象の選択案内
		CLI_ENGINE->GetView()->AddLine("選択範囲外です。もう一度入力してください");
	}

    // ダメージ計算
	int damage = Battle::BattleCalc::CalcDamage(player->GetAttack(),enemyList[number].GetDefence());
	// 計算値を対象に与える。
	enemyList[number].ApplyDamage(damage);
	// 表示用ダメージ値を作成
	std::string log_damage = std::to_string(damage);
	// ログを出す
	CLI_ENGINE->GetView()->AddLine(player->GetName() + "は" + enemyList[number].GetName() + "に" + log_damage + "を与えた。");

}
