#pragma once
#include <iostream>
#include <unordered_map>
#include <memory>
#include "System/Utility/Singleton.hpp"
#include "Application/Charactor/status/CharaStatus.hpp"

namespace Chara
{
	// 前方宣言
	class CharaBase;

	// キャラクターID
	enum class ID : int
	{
		NONE = -1,
		HERO = 0,
		GOBLIN,
		WOLF,
		MAX
	};

	// キャラクター生成
	class Factory : public Singleton<Factory>
	{

		GENERATE_SINGLETON_BODY(Factory);

		// Characterdata
		std::unordered_map<int, Chara::Status> m_characterData;

		/// <summary>
		/// ステータスデータの設定
		/// </summary>
		void OnCreate() override;

	public:

		// 指定したIDでキャラクターを生成する
		std::unique_ptr<Chara::CharaBase> CreateCharacter(int arg_charaId);

	};
}
