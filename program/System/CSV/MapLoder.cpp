#include "MapLoder.h"

std::vector<int> MapLoder::Load(const std::string& arg_filePath)
{

    std::ifstream file(arg_filePath);
    if(!file.is_open()) {
        std::cerr << "ファイルが開けませんでした。" << arg_filePath << std::endl;
        return {};
	}

	std::vector<int> mapData;
	mapData.reserve(MAP_WIDTH * MAP_HEIGHT);

	std::string line;
    while (std::getline(file,line))
    {
		auto values = CSVLoader::Split(line, ',');
        for (auto& v : values) {
            mapData.push_back(v);
        }
    }

	file.close();

    if(mapData.size() != MAP_WIDTH * MAP_HEIGHT) {
        std::cerr << "マップデータのサイズが不正です。" << arg_filePath << std::endl;
        return {};
	}

    // 呼び出し側がデータを保持
    return mapData;
}