#include "Validator.h"



Validator::Validator()
{
}


Validator::~Validator()
{
}

int Validator::intValidator(int min, int max)
{
	cout << "Enter a number between " << min << " and " << max << " : ";
	int userInput = 0;
	bool isValidInput = false;
	while (!isValidInput) {
		cin >> userInput;
		if (cin.fail() || userInput < min || userInput > max) {
			cout << "Please try again : ";
			cin.clear();
			cin.ignore(kEndOfLine, '\n');
		}
		else if (userInput >= min && userInput <= max) {
			isValidInput = true;
		}
	}
	return userInput;
}

string Validator::stringValidator(string desiredField)
{
	cout << "Please enter " << desiredField << " : ";
	string userInput = "";
	cin.ignore(kEndOfLine, '\n');
	getline(cin, userInput);

	bool isValid = false;
	while (!isValid) {
		if (userInput.empty()) {
			cout << "Phrase cannot be empty." << endl
				<< "Please try again : ";
			cin.clear();
			getline(cin, userInput);
		}
		else {
			isValid = true;
		}
	}
	return userInput;
}
