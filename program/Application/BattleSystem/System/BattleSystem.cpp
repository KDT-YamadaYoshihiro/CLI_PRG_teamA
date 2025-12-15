#include "Application/BattleSystem/System/BattleSystem.hpp"
#include "Engine/Engine.hpp"
#include "Application/BattleSystem/calc/BattleCalc.hpp"
#include "System/Input/Key.hpp"
#include "System/Time/Time.hpp"

#include<vector>
#include<string>


/// <summary>
/// バトル中の状態更新
/// </summary>
void Battle::BattleSystem::Update(Chara::Player* player)
{
	m_isFinishd = false;

	CLI_ENGINE->GetView()->ClearLines();

	CLI_ENGINE->GetView()->AddLine("-----------------");
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

	//	行動の実行
	CLI_ENGINE->GetView()->ClearLines();


	//	プレイヤーの攻撃 プレイヤー攻撃力、敵防御力
	auto player_attack = Battle::BattleCalc::CalcDamage(player->GetAttack(),10);

	//	敵の生存判定
		//	生存していたら敵のターン
		//	生存してなかったらバトル終了（フラグを立てる）
		//	関数のリターン

	//	敵の行動（攻撃）

	//	プレイヤーの生存判定

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
