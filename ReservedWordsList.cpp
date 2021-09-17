#include "ReservedWordsList.h"

ReservedWordsList::ReservedWordsList() {}
ReservedWordsList::ReservedWordsList(const std::set<std::string> listOfWords) : listOfReservedWords(listOfWords){}
ReservedWordsList::~ReservedWordsList() {}


bool ReservedWordsList::isReservedWord(const std::string& word) {
	return Instance().privateIsReservedWord(word);
}

ReservedWordsList& ReservedWordsList::Instance() {
	static ReservedWordsList theSingleInstance(initializeFromFile());
	return theSingleInstance;
}

std::set<std::string> ReservedWordsList::initializeFromFile() {

	const std::string path = "reservedWordsList.txt";

	std::ifstream file;
	file.exceptions(std::ifstream::badbit);

	std::string word;
	std::set<std::string> listOfWords;

	try {
		file.open(path);
		while (file >> word)
			listOfWords.insert(word);
		file.close();
	}
	catch(const std::ifstream::failure& error){
		std::cerr << "\n File processing error: " << error.what();
	}
	return listOfWords;
}

bool ReservedWordsList::privateIsReservedWord(const std::string& word) {
	return (listOfReservedWords.find(word) != listOfReservedWords.end());
}