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
		template<typename T>
		std::unique_ptr<T> CreateCharacter(int arg_charaId);

	};

	template<typename T>
	inline std::unique_ptr<T> Factory::CreateCharacter(int arg_charaId)
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
		return std::make_unique<T>(status);
	}
}
