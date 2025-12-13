#include <iostream>
#include "Factory.h"
#include "Application/Charactor/base/CharactorBase.hpp"

Factory::Factory()
{
	// キャラクターデータの初期化
	m_characeterData.enmplace("Hero", Chara::Status{ "勇者",120,120,18,10,12});
	m_characeterData.emplace( "Goblin", Chara::Status{"Goblin",50,50,10,0,4});
	m_characeterData.emplace( "wolf", Chara::Status{"ウルフ",70,70,14,0,6});
}

std::unique_ptr<Chara::CharaBase> Factory::CreateCharacter(const std::string& arg_charaName)
{
	// キャラクターステータスを検索
	auto it = m_characeterData.find(arg_charaName);
	if (it == m_characeterData.end())
	{
		// ステータスが見つからなかったら
		std::cout << "ステータスが見つかりません: " << arg_charaName << std::endl;
		return nullptr;
	}

	// ステートをコピー
	Chara::Status status = it->second;

	// キャラクターオブジェクトを生成して返す
	return std::unique_ptr<Chara::CharaBase>(status);
}
