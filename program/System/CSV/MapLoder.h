#pragma once
#include "CSVLoader.h"
#include <unordered_map>
#include <fstream>
#include <iostream>

// マップCSV読み込みクラス
class MapLoder
{
public:

	// マップサイズ
	static constexpr int MAP_WIDTH = 20;
	static constexpr int MAP_HEIGHT = 20;

	// デストラクタ
	~MapLoder() = default;

	// 読み込み
	static std::vector<int> Load(const std::string& arg_filePath);


};

