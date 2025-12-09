#pragma once
#include "Application/Inventory/Item/base/Item.hpp"

namespace Inventory
{
	struct HealingItem : public Item
	{
		unsigned int heal = 1;

		unsigned int GetHealPoint()const
		{
			return heal;
		}
	};
}