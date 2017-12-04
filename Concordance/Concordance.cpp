#include "Concordance.h"


Concordance::Concordance() {}

Concordance::Concordance(string fileName)
{
	fillFromFile(fileName);
	sortListByWords();
	saveToFile(fileName);
}


Concordance::~Concordance()
{
}

void Concordance::fillFromFile(string fileName)
{
	int numberOfLines = 1;
	ifstream fin;
	fin.open(fileName);
	while (!fin.eof) {
		string word = "";
		fin >> word;
		string formattedWord = wordFormatter(word);
		addOrUpdateWord(formattedWord, numberOfLines);
		if (word.find('\n') != string::npos) {
			numberOfLines++;
		}
	}

	fin.close();
}

void Concordance::saveToFile(string fileName)
{
	string concordanceFileName = "";
	concordanceFileName.append("ConcordanceOf");
	concordanceFileName.append(fileName);
	ofstream fout;
	fout.open(concordanceFileName);
	for (vector<Word>::iterator it = _wordList.begin(); it != _wordList.end(); it++){
		fout << it->toString() << endl;
	}
	fout.close();
}

void Concordance::addOrUpdateWord(string word, int lineNumber)
{
	bool isAlreadyListed = false;
	for (vector<Word>::iterator it = _wordList.begin(); it != _wordList.end(); it++) {
		if (it->getWord().compare(word) == 0) {
			isAlreadyListed = true;
			it->incrementWordCount();
			it->addLineOccurrence(lineNumber);
		}
	}
	if (!isAlreadyListed) {
		Word newWord = Word(word);
		newWord.addLineOccurrence(lineNumber);
		_wordList.push_back(newWord);
	}
}

void Concordance::sortListByWords()
{
	sort(_wordList.begin(), _wordList.end());
}

string Concordance::wordFormatter(string word)
{
	string formattedWord = word;
	for (int index = 0; index < formattedWord.size(); index++) {
		if (ispunct(formattedWord[index])) {
			if (!isalpha(formattedWord[index + 1])) {
				formattedWord.erase(index, 1);
			}
		}
		else if (formattedWord[index] == ' ') {
			formattedWord.erase(index, 1);
		}
		formattedWord[index] = tolower(formattedWord[index]);
	}

	return formattedWord;
}

