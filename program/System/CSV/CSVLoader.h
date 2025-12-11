#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

// CSV読み込み基底クラス
class CSVLoader {

protected:
	
	
	// 文字列を区切り文字で分割し、指定された型に変換するテンプレート関数
	template<typename T>
	static std::vector<T> Split(const std::string& line, T(*converter)(const std::string&), char delimiter = ',') {

		std::vector<T> result;
		std::stringstream ss(line);
		std::string item;

		while (std::getline(ss, item, delimiter)) {
			result.push_back(converter(item));
		}
		return result;
	}


public:

	// CSVファイルを読み込み、各行を文字列のベクターとして返す
	static std::vector<std::string> LoadCSV(const std::string& filePath) {
	
		std::ifstream file(filePath);
		std::vector<std::string> lines;

		if (!file.is_open()) {
			throw std::runtime_error("ファイルが開けませんでした: " + filePath);
		}

		std::string line;
		while (std::getline(file, line)) {
			lines.push_back(line);
		}
		file.close();
		return lines;
	}


	// デストラクタ
	~CSVLoader() = default;

};