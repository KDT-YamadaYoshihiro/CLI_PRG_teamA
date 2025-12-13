#include "Factory.h"
#include "Application/Charactor/base/CharactorBase.hpp"

/// <summary>
/// ステータスデータの設定
/// </summary>
void Chara::Factory::OnCreate()
{
	// キャラクターデータの初期化
	m_characterData.emplace(static_cast<int>(Chara::ID::HERO), Chara::Status{ "勇者",		120,120, 18, 10, 12 });
	m_characterData.emplace(static_cast<int>(Chara::ID::GOBLIN), Chara::Status{ "ゴブリン",	 50, 50, 10,  0,  4 });
	m_characterData.emplace(static_cast<int>(Chara::ID::WOLF), Chara::Status{ "ウルフ",		 70, 70, 14,  0,  6 });
}


// 指定したIDでキャラクターを生成する
std::unique_ptr<Chara::CharaBase> Chara::Factory::CreateCharacter(int arg_charaId)
{
	// キャラクターステータスを検索
	auto it = m_characterData.find(arg_charaId);
	if (it == m_characterData.end())
	{
		// ステータスが見つからなかったら
		std::cout << "ステータスが見つかりません: " << arg_charaId << std::endl;
		return nullptr;
	}

	// ステートをコピー
	Chara::Status status = it->second;

	// キャラクターオブジェクトを生成して返す
	return std::make_unique<Chara::CharaBase>(status);
}
