#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include "Word.h"

using namespace std;

class Concordance
{
private:
	vector<Word> _wordList;

public:
	Concordance();
	Concordance(string fileName);
	~Concordance();

	void fillFromFile(string fileName);

	void saveToFile(string fileName);

	void addOrUpdateWord(string word, int lineNumber);

	void sortListByWords();

	string wordFormatter(string word);
	
};

