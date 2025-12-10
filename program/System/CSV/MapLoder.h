#pragma once
#include "CSVLoader.h"
#include <unordered_map>
#include <fstream>
#include <iostream>

// マップCSV読み込みクラス
class MapLoder : public CSVLoader
{
private:
	
	// マップデータ
	std::unordered_map<int, std::vector<std::vector<int>>> m_maps;
	// マップサイズ
	const int MAP_WIDTH = 20;
	const int MAP_HEIGHT = 20;

public:

	// デストラクタ
	~MapLoder() = default;

	// 読み込み
	bool Load(int arg_mapID, const std::string& arg_filePath);

	// マップデータ取得
	const std::vector<int>* GetMap(int arg_mapID) const;

	// 個別タイルの取得
	int GetTile(int arg_mapId, int arg_x, int arg_y) const;

};

