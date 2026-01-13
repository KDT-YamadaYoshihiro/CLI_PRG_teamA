#pragma once
#include <string>
#include<vector>
#include<unordered_map>

namespace Magic
{
	enum class Type : int 
	{
		Fire,
		Freeze,
		Thunder
	};

	struct Data {
		std::string Name;
		int CostMP;
		int Power;
	};

	/// <summary>
	///	魔法のデータの管理
	/// </summary>
	class Manager
	{
	public:
		Manager();
		virtual ~Manager() = default;

		/// <summary>
		/// 魔法の情報を取得
		/// </summary>
		/// <param name="index"></param>
		/// <returns>データ</returns>
		Data GetMagicData(int index);

		/// <summary>
		/// コレクション内の魔法名をすべて取得
		/// </summary>
		/// <returns></returns>
		std::vector<std::string> GetAllNames();

	private:
		std::vector<Data> m_magicData;
	};
}

