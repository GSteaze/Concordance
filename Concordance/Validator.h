#include <iostream>
#include <string>

using namespace std;

class Validator
{
private:
	const static int kEndOfLine = 1024;

public:
	Validator();
	~Validator();

	int static intValidator(int min, int max);
	string static stringValidator(string desiredField);
};

