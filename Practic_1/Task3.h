#pragma once
#include <iostream>
#include <string>
#include <vector>

class Task3
{
private:
	std::string text;
	int GetUpperLettersCount();
	std::vector<std::string> SplitTextByWords();
	std::vector<std::string> FindShortestWords(std::vector<std::string> words);
	std::vector<std::string> DeleteWordsWithLowercase(std::vector<std::string> words);
public:
	void Execute(std::string text);
};

