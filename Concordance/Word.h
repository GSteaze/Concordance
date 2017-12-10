#pragma once
#include <string>
#include <vector>

using namespace std;

class Word
{
private:
	string _word;
	int _wordCount;
	vector<int> _lineOccurrence;

public:
	Word();
	Word(string word);
	~Word();

	void setWord(string word);
	string getWord();

	bool setWordCount(int count);
	void incrementWordCount();
	int getWordCount();

	void addLineOccurrence(int lineNumber);
	vector<int> getLineOccurrence();

	string toString();

	bool operator< (Word &rhs) {
		if (this->getWord().compare(rhs.getWord()) < 0) {
			return true;
		}
		else {
			return false;
		}
	}

	Word& Word::operator=(Word &rhs) {
		if (this != &rhs) {
			this->setWord(rhs.getWord());
			this->setWordCount(rhs.getWordCount());
			this->_lineOccurrence = rhs._lineOccurrence;
		}
		return *this;
	}
};

