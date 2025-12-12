#pragma once
#include <unordered_map>
#include <memory>

#include "Application/Charactor/status/CharaStatus.hpp"

// 前方宣言
namespace Chara
{
	class CharaBase;
}

class Factory
{

	// Characterdata
	std::unordered_map<std::string, Chara::Status> m_characterData;

public:

	// 指定したIDでキャラクターを生成する
	static std::shared_ptr<Chara::CharaBase> CreateCharacter(const std::string& arg_charaId);

};

