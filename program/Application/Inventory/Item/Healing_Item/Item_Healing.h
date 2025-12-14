#pragma once
#include "Application/Inventory/Item/base/Item.h"

namespace Inventory
{

	// ‰ñ•œƒAƒCƒeƒ€
	class Item_Healing : public Inventory::Item
	{
		// ‰ñ•œ—Ê
		int m_heal = 1;

	public:

		Item_Healing(int heal)
			:Item("Potion"), m_heal(heal)
		{
		}

		
		unsigned int GetHealPoint()const
		{
			return m_heal;
		}

		void Use(Chara::CharaBase* character) override;

	};
}

