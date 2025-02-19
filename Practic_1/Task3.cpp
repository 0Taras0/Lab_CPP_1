#include "Task3.h"

using namespace std;

int Task3::GetUpperLettersCount()
{
	int count = 0;
	for (int i = 0; i < text.length(); i++)
		if (isupper(text[i]))
			count++;
	return count;
}

vector<string> Task3::SplitTextByWords()
{
	vector<string> words;
	string word = "";
	for (int i = 0; i < text.length(); i++)
	{
		if (isalpha(text[i]))
			word += text[i];
		else
		{
			if (word.length() > 0)
			{
				words.push_back(word);
				word = "";
			}
		}
	}
	if (word.length() > 0)
		words.push_back(word);
	return words;
}

vector<string> Task3::FindShortestWords(vector<string> words)
{
	int n = words.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (words[j].size() > words[j + 1].size()) {
				swap(words[j], words[j + 1]);
			}
		}
	}
	return words;
}

vector<string> Task3::DeleteWordsWithLowercase(vector<string> words)
{
	vector<string> filteredWords;
	for (const auto& word : words) {
		if (!islower(word[0])) {
			filteredWords.push_back(word);
		}
	}
	return filteredWords;
}

void Task3::Execute(string text)
{
	this->text = text;
	cout << "Number of uppercase letters: " << GetUpperLettersCount() << endl;

	vector<string> words = SplitTextByWords();
	vector<string> shortestWords = FindShortestWords(words);

	cout << "Shortest words: ";
	for (const auto& word : shortestWords)
		cout << word << " ";
	cout << endl;

	vector<string> filteredWords = DeleteWordsWithLowercase(words);
	cout << "Words without lowercase: ";
	for (const auto& word : filteredWords)
		cout << word << " ";
	cout << endl;
}
