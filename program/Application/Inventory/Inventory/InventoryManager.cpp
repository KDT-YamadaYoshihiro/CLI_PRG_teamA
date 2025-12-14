#include "InventoryManager.hpp"
#include "Application/Charactor/base/CharactorBase.hpp"

std::vector<std::string> Inventory::InventoryManager::GetAllNames()
{
	// アイテム名を格納するベクターを準備
	std::vector<std::string> names;
	// ベクターの容量をインベントリ内のアイテム数に合わせて確保
	names.reserve(m_items.size());

	// インベントリ内の全てのアイテムの名前を取得
	for (const auto& item : m_items)
	{
		names.push_back(item->GetName());
	}

	// 取得した名前のリストを返す
	return names;

}

void Inventory::InventoryManager::AddItem(std::unique_ptr<Item> item)
{
	// アイテムをインベントリに追加
	m_items.push_back(std::move(item));
}

void Inventory::InventoryManager::UseItem(int index, Chara::CharaBase* character)
{
	// インデックスが範囲外かどうかをチェック
    if(index >= m_items.size())
    {
		// インデックスが範囲外の場合は何もしない
        return;
	}

	// アイテムの使用処理を呼び出す
    m_items[index]->Use(character);
	// 使用したアイテムをインベントリから削除する
	m_items.erase(m_items.begin() + index);

}

int Inventory::InventoryManager::GetItemCount() const
{
	return m_items.size();
}
