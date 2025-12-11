#pragma once
#include <string>
#include <vector>
#include <sstream>

// CSV読み込み基底クラス
class CSVLoader {

public:

	/// <summary>
	/// CSVの1行を分割してint型のベクターで返す
	/// </summary>
	/// <param name="line"></param>
	/// <param name="delimiter"></param>
	/// <returns>std::vector<int> result </returns>
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