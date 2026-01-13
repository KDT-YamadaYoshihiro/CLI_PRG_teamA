#include "MagicManager.h"
#include <iostream>
#include <System/Utility/Define.hpp>

Magic::Manager::Manager()
{
	m_magicData.push_back({ "ファイア",5,20 });
	m_magicData.push_back({ "サンダー",7,25 });
	m_magicData.push_back({ "フリーズ",10,30 });
}

Magic::Data Magic::Manager::GetMagicData(int index)
{
	const bool IndexInRange = static_cast<size_t>(index) < m_magicData.size();
	if (IndexInRange)
	{
		return m_magicData[index];
	}

	//	入ることはないはずだけどもしものためにブレークで止めます
	DEBUG_BREAK;
	return Data();
}

/// <summary>
/// コレクション内の魔法名をすべて取得
/// </summary>
/// <returns></returns>
std::vector<std::string>Magic::Manager::GetAllNames() 
{
	std::vector<std::string> names;
	for(auto& data : m_magicData)
	{
		names.push_back(data.Name);
	}
	return names;
}