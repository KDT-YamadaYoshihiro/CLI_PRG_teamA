#include <iostream>
#include "Factory.h"
#include "Application/Charactor/base/CharactorBase.hpp"

std::shared_ptr<Chara::CharaBase> Factory::CreateCharacter(const std::string& arg_charaName)
{
	
	const Chara::Status* status /* = ファイルからステータスを取得 */ ;
	if (!status)
	{
		// ステータスが見つからなかったら
		std::cout << "ステータスが見つかりません: " << arg_charaName << std::endl;
		return nullptr;
	}


	return std::make_shared<Chara::CharaBase>(status);
}
