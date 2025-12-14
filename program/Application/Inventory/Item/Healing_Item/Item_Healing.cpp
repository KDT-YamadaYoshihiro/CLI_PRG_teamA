#include "Item_Healing.h"
#include "Application/Charactor/Player/Player.hpp"

void Inventory::Item_Healing::Use(Chara::CharaBase* character)
{

	// プレイヤーが存在しない場合は処理しない
	if(!character)
	{
		return;
	}

	// プレイヤーの体力を回復する
	character->Heal(m_heal);

}
