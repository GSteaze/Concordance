#include "Word.h"



Word::Word()
{
	setWord("");
	setWordCount(0);
}

Word::Word(string word)
{
	setWord(word);
	setWordCount(0);
}


Word::~Word()
{
}

void Word::setWord(string word)
{
	string formattedWord = word;
	for (int index = 0; index < formattedWord.size(); index++) {
		formattedWord[index] = tolower(formattedWord[index]);
	}
	_word = formattedWord;
}

string Word::getWord()
{
	return _word;
}

bool Word::setWordCount(int count)
{
	if (count >= 0) {
		_wordCount = count;
		return true;
	}
	else {
		return false;
	}
}

void Word::incrementWordCount()
{
	_wordCount++;
}

int Word::getWordCount()
{
	return _wordCount;
}

void Word::addLineOccurrence(int lineNumber)
{
	bool isAlreadyListed = false;

	for (int index = 0; index < _lineOccurrence.size(); index++) {
		if (lineNumber == _lineOccurrence[index]) {
			isAlreadyListed = true;
		}
	}

	if (!isAlreadyListed) {
		_lineOccurrence.push_back(lineNumber);
	}
}

vector<int> Word::getLineOccurrence()
{
	return _lineOccurrence;
}

string Word::toString()
{
	string formattedString = "";
	formattedString.append(_word);
	formattedString.append("(occurrences): ");
	if (_lineOccurrence.empty()) {
		formattedString.append("No occurrences");
	}
	else {
		for (int index = 0; index < _lineOccurrence.size(); index++) {
			formattedString.append(to_string(_lineOccurrence[index]));

			if (index != _lineOccurrence.size() - 1) {
				formattedString.append(", ");
			}
		}
	}
	return formattedString;
}
