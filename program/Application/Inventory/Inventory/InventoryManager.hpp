#pragma once
#include"System/Utility/Singleton.hpp"
#include "Application/Inventory/Item/base/Item.hpp"

#include<vector>
#include<memory>

namespace Inventory
{
	/// <summary>
	/// インベントリ内のアイテム管理
	/// </summary>
	class InventoryManager
	{
	public:
		/// <summary>
		/// インベントリ内のアイテムの名前を取得する
		/// </summary>
		/// <returns></returns>
		std::vector<std::string> GetAllNames();
	private:
		/// <summary>
		/// プレイヤーの所持しているインベントリ
		/// </summary>
		/// 別にここはvectorである必要ないので型ごとの名前でソートされるようにmapを使うほうがいいのかもしれない
		std::vector<std::unique_ptr<Item>> m_items;
	};
}