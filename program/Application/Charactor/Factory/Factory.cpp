#include "Factory.h"
#include "Application/Charactor/base/CharactorBase.hpp"
#include "Application/Charactor/Player/Player.hpp"
#include "Application/Charactor/Enemy/Enemy.h"

/// <summary>
/// ステータスデータの設定
/// </summary>
void Chara::Factory::OnCreate()
{
	// キャラクターデータの初期化
	m_characterData.emplace(static_cast<int>(Chara::ID::HERO), Chara::Status{ "勇者",				120,120,  38,  24, 12 });
	m_characterData.emplace(static_cast<int>(Chara::ID::GOBLIN), Chara::Status{ "ゴブリン",			 40, 40,  10,   0,  4 });
	m_characterData.emplace(static_cast<int>(Chara::ID::WOLF), Chara::Status{ "ウルフ",				 50, 50,  14,   0,  6 });
	m_characterData.emplace(static_cast<int>(Chara::ID::BOSS), Chara::Status{ "インフェルノウルフ",	 80, 80,  42,  28,  8});
}