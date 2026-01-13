#include "Item_Healing.h"
#include "Application/Charactor/Player/Player.hpp"
#include "Engine/Engine.hpp"

void Inventory::Item_Healing::Use(Chara::CharaBase* character)
{

	// プレイヤーが存在しない場合は処理しない
	if(!character)
	{
		return;
	}

	// プレイヤーの体力を回復する
	character->Heal(m_heal);
	std::string heal = std::to_string(m_heal);
	CLI_ENGINE->GetView()->AddLine(character->GetName() + "は" + heal + "回復した。");
}
