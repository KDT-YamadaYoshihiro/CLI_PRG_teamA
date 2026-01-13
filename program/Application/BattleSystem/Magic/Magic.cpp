#include "Magic.h"
#include "Application/Charactor/Player/Player.hpp"
#include "Application/Charactor/Enemy/Enemy.h"
#include "Application/BattleSystem/action/Calc/BattleCalc.hpp"
#include "Engine/Engine.hpp"


void Magic::MagicAction::MagicAttack(Chara::Player* player, std::vector<Chara::Enemy*> enemylist,int index)
{
	// cinを使用して入力
	int number = enemylist.size();
	if (enemylist.size() > 1)
	{
		std::string count = std::to_string(enemylist.size() - 1);
		// 対象の選択案内
		CLI_ENGINE->GetView()->AddLine("対象を０から" + count + "の中から選んでください");
		CLI_ENGINE->GetView()->Render();
		std::cin >> number;
		// 選択範囲内になるまでループ
		while (number >= enemylist.size())
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

	// 魔法用のダメージ計算
	static Magic::Manager manager;
	Data magicData = manager.GetMagicData(index);

	// 計算値を対象に与える。
	int damage = Battle::BattleCalc::CalcMagicDamage(player->GetMagicAttack(), magicData.Power, enemylist[number]->GetDefence());

	enemylist[number]->ApplyDamage(damage);
	// 表示用ダメージ値を作成
	std::string log_damage = std::to_string(damage);
	// ログを出す
	CLI_ENGINE->GetView()->AddLine("\n" + player->GetName() + "は" + enemylist[number]->GetName() + "に" + magicData.Name + "で" + log_damage + "を与えた。");
	CLI_ENGINE->GetView()->Render();
	CLI_ENGINE->GetTimer()->Sleep(std::chrono::milliseconds(500));

}
