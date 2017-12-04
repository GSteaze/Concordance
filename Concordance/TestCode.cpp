#include "TestCode.h"



TestCode::TestCode()
{
	testWord();
	testConcordance();
}


TestCode::~TestCode()
{
}

void TestCode::testWord()
{
	cout << endl << "Testing Word" << endl;

	Word testWord = Word();
	testWord.setWord("Testing");
	cout << "Word : " << testWord.getWord() << endl;
	cout << "Word Count : " << testWord.getWordCount() << endl;
	cout << "To String : " << testWord.toString() << endl;

	testWord.setWordCount(3);
	cout << "Word Count set to 3 : " << testWord.getWordCount() << endl;

	testWord.incrementWordCount();
	cout << "Word count increment to 4 : " << testWord.getWordCount() << endl;

	testWord.addLineOccurrence(1);
	cout << "LineOccurrence at 1" << testWord.toString() << endl;

	testWord.addLineOccurrence(2);
	cout << "Add line occurrence at 2" << testWord.toString() << endl;



	cout << endl << "Word Tested" << endl;
}

void TestCode::testConcordance()
{
	cout << endl << "Testing Concordance" << endl;

	Concordance test = Concordance();
	test.fillFromFile("TestFile.txt");

	cout << endl << "Concordance Tested" << endl;
}

void TestCode::testMenuIO()
{
	cout << endl << "Testing MenuIO" << endl;




	cout << endl << "MenuIO Tested" << endl;
}
