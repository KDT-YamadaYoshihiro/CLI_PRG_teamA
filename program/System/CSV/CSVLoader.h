#pragma once
#include <string>
#include <vector>
#include <sstream>

// CSV読み込み基底クラス
class CSVLoader {

public:

	// コンマ区切り
	static std::vector<int> Split(const std::string& line, char delimiter = ',') {

		std::vector<int> result;
		std::stringstream ss(line);
		std::string item;

		while (std::getline(ss, item, delimiter)) {
			result.push_back(std::stoi(item));
		}
		return result;
	}

	~CSVLoader() = default;

};