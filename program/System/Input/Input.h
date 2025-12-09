#pragma once
#include <iostream>

namespace ConsoleInput {

	char GetChar() {
		return std::cin.get();
	}

	std::string GetString() {
		std::string input;
		std::getline(std::cin, input);
		return input;
	}
}