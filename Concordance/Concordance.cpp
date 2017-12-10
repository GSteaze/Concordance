#include "Concordance.h"


Concordance::Concordance() {}

Concordance::Concordance(string fileName)
{
	cout << "Starting Concordance." << endl;
	fillFromFile(fileName);
	sortListByWords();
	saveToFile(fileName);
	cout << "Concordance Completed." << endl;
}


Concordance::~Concordance()
{
}

void Concordance::fillFromFile(string fileName)
{
	int numberOfLines = 0;
	ifstream fin;
	fin.open(fileName);
	while (!fin.eof()) {
		string line = "";
		getline(fin, line);
		numberOfLines++;

		//cout << line << endl;

		string word = "";
		size_t pos = 0;
		do {
			while (line[0] == ' ') {
				line.erase(0, 1);
			}
			pos = line.find(' ');
			word = line.substr(0, pos);

			//cout << "word : " << endl;

			bool isContainsWord = false;
			for (int i = 0; i < word.size(); i++) {
				if (isalpha(word[i])) {
					isContainsWord = true;
				}
				if (isalnum(word[i])) {
					isContainsWord = true;
				}
			}
			if (isContainsWord) {
				word = wordFormatter(word);
				addOrUpdateWord(word, numberOfLines);

				//cout << word << endl;

				line.erase(0, pos + 1);
			}
		} while ((pos = line.find(' ')) != string::npos);
		if (!line.empty()) {
			word = wordFormatter(line);
			if (!word.empty()) {
				addOrUpdateWord(word, numberOfLines);
			}
		}
	}
	fin.close();
}

void Concordance::newFillFromFile(string fileName)
{
	ifstream fin;
	fin.open(fileName);

	int lineNumber = 0;
	while(!fin.eof()){
		string line = "";
		getline(fin, line);

		cout << "Getline : " << line << endl;

		lineNumber++;

		bool isWithinWord = false;
		bool isCompleteWord = false;
		int start = 0;
		int end = 0;
		for (int index = 0; index < line.size(); index++) {

			cout << "IsWithin : " << isWithinWord << "\tisComplete" << isCompleteWord << endl;

			if ((line[index] != ' ') && !isWithinWord) {
				start = index;

				cout << "New start : " << start << endl;

				isWithinWord = true;
			}
			if ((line[index] == ' ') && isWithinWord) {
				end = index - 1;

				cout << "New word end : " << end << endl;

				isCompleteWord = true;
			}
			if ((index = line.size() - 1) && isWithinWord) {
				end = index;
				
				cout << "New word end of line : " << end << endl;

				isCompleteWord = true;
			}
			if (isCompleteWord) {
				string word = line.substr(start, (end - start));

				cout << "Unformatted word : " << word << endl;

				word = wordFormatter(word);
				addOrUpdateWord(word, lineNumber);
				line.erase(start, (end - start));

				cout << "Line after erase : " << line << endl;

				start = 0;
				isWithinWord = false;
				isCompleteWord = false;
				index = 0;

				cout << "Word : " << word << endl;

			}
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
			bool isEmbedded = false;
			if (index > 0) {
				isEmbedded = isalpha(formattedWord[index - 1]) && isalpha(formattedWord[index + 1]);
			}
			if (!isEmbedded){
				while (ispunct(formattedWord[index])) {
					formattedWord.erase(index, 1);
				}
				if (index != 0) {
					index--;
				}
			}
		}
		else if (formattedWord[index] == ' ') {
			while (formattedWord[index] == ' ') {
				formattedWord.erase(index, 1);
			}
			if (index != 0) {
				index--;
			}
		}
		formattedWord[index] = tolower(formattedWord[index]);
	}

	return formattedWord;
}

