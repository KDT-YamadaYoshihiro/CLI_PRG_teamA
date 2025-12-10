#pragma once
#include<string>


namespace Inventory
{
	struct Item
	{
		virtual ~Item() = default;

		int id = -1;
		std::string name;
		//	種別を付ければ強化アイテムとかも可能（今回は回復だけ）
	};
}
