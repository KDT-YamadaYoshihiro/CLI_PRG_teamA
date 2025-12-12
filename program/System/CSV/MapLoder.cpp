#include "MapLoder.h"
#include "System/Utility/Define.hpp"


std::vector<std::vector<int>> MapLoder::Load(const std::string& arg_filePath)
{

	// マップデータ格納用
	std::vector<std::vector<int>> mapData;
	// CSVファイル読み込み
	auto lines = CSVLoader::LoadCSV(arg_filePath);

	// マップデータ用のメモリ確保
	mapData.reserve(lines.size());

	// 各行を分割して整数に変換
    for(auto& line : lines) {
        mapData.push_back(Split<int>(line, ToInt));
    }

	// マップサイズの確認
	if (mapData.size() <= 0 )
	{
		DEBUG_BREAK;
		return std::vector<std::vector<int>>();
	}
	else if (mapData[0].size() <= 0)
	{
		DEBUG_BREAK;
		return std::vector<std::vector<int>>();
	}

    // 呼び出し側がデータを保持
    return mapData;
}