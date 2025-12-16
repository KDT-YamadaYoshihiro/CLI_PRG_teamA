#pragma once
#include "System/Utility/Singleton.hpp"
#include "Application/Inventory/Item/base/Item.h"

#include<vector>
#include<memory>

namespace Chara
{
	class CharaBase;
}

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

		/// <summary>
		///	アイテムをインベントリに追加する
		/// </summary>
		/// <param name="item"></param>
		void AddItem(std::unique_ptr<Item> item);

		/// <summary>
		///	アイテムを使用する
		/// </summary>
		/// <param name="index"></param>
		/// <param name="player"></param>
		void UseItem(int index, Chara::CharaBase* character);

		/// <summary>
		/// アイテムの数を取得する
		/// </summary>
		/// <returns></returns>
		int GetItemCount() const;

	private:
		/// <summary>
		/// プレイヤーの所持しているインベントリ
		/// </summary>
		/// 別にここはvectorである必要ないので型ごとの名前でソートされるようにmapを使うほうがいいのかもしれない
		std::vector<std::unique_ptr<Item>> m_items;
	};
}