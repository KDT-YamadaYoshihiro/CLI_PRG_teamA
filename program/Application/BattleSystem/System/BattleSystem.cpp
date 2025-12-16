#include "Application/BattleSystem/System/BattleSystem.hpp"
#include "Engine/Engine.hpp"
#include "Application/BattleSystem/calc/BattleCalc.hpp"
#include "System/Input/Key.hpp"
#include "System/Time/Time.hpp"

#include<vector>
#include<string>

#include "Application/BattleSystem/Target/TargetAttack.h"
#include "../Magic/Magic.h"

/// <summary>
/// バトル中の状態更新
/// </summary>
void Battle::BattleSystem::Update(Chara::Player* player, const std::vector<Chara::Enemy*>& enemys)
{
	m_isFinishd = false;

	//CLI_ENGINE->GetTimer()->Sleep(std::chrono::seconds(1));

	if (enemys.empty())
	{
		m_isFinishd = true;
		return;
	}

	//	全消し
	CLI_ENGINE->GetView()->ClearLines();

	CLI_ENGINE->GetView()->AddLine("-----------------");

	//	プレイヤーのステータス表示
	CLI_ENGINE->GetView()->AddLine(player->GetStatusString() + "\n");
	//	敵ステータス表示
	for (auto& enemy : enemys)
	{
		CLI_ENGINE->GetView()->AddLine(enemy->GetStatusString());
	}

	CLI_ENGINE->GetView()->AddLine("\n-----------------");
	CLI_ENGINE->GetView()->AddLine("プレイヤーのターン");

	//	テスト用のデータ
	std::vector<std::string> Items;
	Items.push_back("ポーション");
	Items.push_back("ポーション");
	Items.push_back("ポーション");
	Items.push_back("ハイポーション");

	std::vector<std::string> magic; 
	magic.push_back("ファイア");
	magic.push_back("サンダー");
	magic.push_back("フリーザ");

	//	プレイヤーの行動選択
	auto action = ActionSelector::SelectCommand(magic, Items);

	//	不要な文字列の削除
	CLI_ENGINE->GetView()->ClearLines();

	//	プレイヤーのステータス表示
	CLI_ENGINE->GetView()->AddLine(player->GetStatusString() + "\n");
	//	敵ステータス表示
	for (auto& enemy : enemys)
	{
		CLI_ENGINE->GetView()->AddLine(enemy->GetStatusString());
	}

	//	行動の選択によって内容を変更する
	switch (action.command)
	{
	case Battle::ePlayerCommand::Attack:
		Battle::Action::Attack(player, enemys);
		break;
	case Battle::ePlayerCommand::Magic:
		Magic::MagicAction::MagicAttack(player, enemys, action.selectID);
		break;
	case Battle::ePlayerCommand::Item:
		break;

	default:
		break;
	};


	//	敵の生存判定
	//	全滅しているとき
	if (enemys.empty())
	{
		//	バトルを終了する
		m_isFinishd = true;
		return;
	}

	CLI_ENGINE->GetTimer()->Sleep(std::chrono::milliseconds(500));

	//	敵の行動（攻撃）
	for (auto& enemy : enemys)
	{
		//	敵の攻撃とダメージ計算
		auto damage = Battle::BattleCalc::CalcDamage(enemy->GetAttack(),player->GetDefence());
		player->ApplyDamage(damage);

		//	攻撃ログを流す
		std::string log = "\n" + enemy->GetName() + "の攻撃";
		CLI_ENGINE->GetView()->AddLine(log);
		CLI_ENGINE->GetView()->Render();
		CLI_ENGINE->GetTimer()->Sleep(std::chrono::milliseconds(500));
		log.clear();
		//	被弾ログを流す
		log = player->GetName() + "に" + std::to_string(damage) + "のダメージ\n";
		CLI_ENGINE->GetView()->AddLine(log);
		CLI_ENGINE->GetView()->Render();
		CLI_ENGINE->GetTimer()->Sleep(std::chrono::milliseconds(500));
	}

	//	表示
	CLI_ENGINE->GetView()->Render();

	//	プレイヤーのが死亡していたら
	//	バトル終了
	if (player->IsDead())
	{
		m_isFinishd = true;
		return;
	}

	//	上に戻る


	//	ウェイトをかける
	CLI_ENGINE->GetTimer()->Sleep(std::chrono::seconds(1));

	//	デバック用
#ifdef _DEBUG
	if (_kbhit())
	{
		if (Input::GetKey().code == Input::KeyCode::Space)
		{
 			m_isFinishd = true;
		}
	}
#endif // _DEBUG

}
