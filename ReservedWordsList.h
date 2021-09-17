#pragma once
#include <iostream>
#include <fstream>
#include <set>

class ReservedWordsList {
	public:
		static bool isReservedWord(const std::string& word);
	private:
		ReservedWordsList();
		ReservedWordsList(const std::set<std::string>);
		ReservedWordsList(const ReservedWordsList& other) = delete;
		ReservedWordsList& operator=(const ReservedWordsList&) = delete;
		~ReservedWordsList();

		static ReservedWordsList& Instance();
		static std::set<std::string> initializeFromFile();
		bool privateIsReservedWord(const std::string& word);

		std::set<std::string> listOfReservedWords;
};