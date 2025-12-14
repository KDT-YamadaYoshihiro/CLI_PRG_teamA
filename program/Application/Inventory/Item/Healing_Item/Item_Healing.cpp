#include "Item_Healing.h"
#include "Application/Charactor/Player/Player.hpp"

void Inventory::Item_Healing::Use(Chara::Player* player)
{

	// プレイヤーが存在しない場合は処理しない
	if(!player)
	{
		return;
	}

	// プレイヤーの体力を回復する
	player->Heal(m_heal);

}
