#pragma once
#include "CSVLoader.h"
#include <unordered_map>
#include <fstream>
#include <iostream>

// マップCSV読み込みクラス
class MapLoder : public CSVLoader
{
private:

	// 文字列を整数に変換する
	static int ToInt(const std::string& str) {
		return std::stoi(str);
	}

public:

	// マップサイズ
	static constexpr int MAP_WIDTH = 20;
	static constexpr int MAP_HEIGHT = 20;

	// デストラクタ
	~MapLoder() = default;

	// csvファイルからマップデータを読み込む
	static std::vector<std::vector<int>> Load(const std::string& arg_filePath);


};

