#pragma once
#include <string>
#include <memory>

namespace Chara
{
	class CharaBase;
}

namespace Inventory
{

	class Item
	{
	
	protected:

		std::string m_name;

	public:

		// コンストラクタ
		explicit Item(const std::string& name)
			:m_name(name)
		{
		}

		virtual ~Item() = default;

		// アイテム使用時の処理
		virtual void Use(Chara::CharaBase* character) = 0;

		// アイテムの名前を取得
		const std::string GetName() const { return m_name; }

	};
}