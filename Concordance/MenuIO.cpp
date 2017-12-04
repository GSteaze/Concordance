#include "MenuIO.h"



MenuIO::MenuIO()
{
}


MenuIO::~MenuIO()
{
}

void MenuIO::displayWelcome()
{
	cout << "Welcome to Concordance!" << endl;
}

void MenuIO::displayTextOptions()
{
	cout << "Available Texts : " << endl
		<< "1. Apology by Plato" << endl
		<< "2. A Modest Proposal by Jonathan Swift" << endl
		<< "3. The Adventures of Sherlock Holmes by Sir Arthur Conan Doyle" << endl
		<< "4. The Wonderful Wizard Of Oz by Frank Baum" << endl
		<< "5. Quit" << endl << endl;
}

void MenuIO::userTextSelection()
{
	string fileName = "";
	int userSelection = Validator::intValidator(1, 4);
	switch (userSelection) {
	case 1: fileName = "Apology.txt";
		break;
	case 2: fileName = "ModestProposal.txt";
		break;
	case 3: fileName = "Sherlock.txt";
		break;
	case 4: fileName = "WizardOfOz.txt";
		break;
	default: cout << "Invalid selection." << endl;
		break;
	}
	Concordance concordance = Concordance(fileName);
}
