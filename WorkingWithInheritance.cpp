#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class fileNotFoundException : public std::exception {
public:
	const char* what() const noexcept override
	{
		return "File was not found";
	}
};

float divide(int number) {
	if (number == 0) {
		throw invalid_argument("Can't divide by 0");
	}
	return 1024.0f / number;
}

string openFile(string file) {
	if (file == "file.txt") {
		return "File was succesfuly opened";
	}
	throw fileNotFoundException();
}

string removeSpaces(char* arr) {

	char separator = ' ';
	int i = 0;

	// Temporary string used to split the string.
	string s;
	while (arr[i] != '\0') {
		if (arr[i] != separator) {
			// Append the char to the temp string.
			s += arr[i];
		}
		i++;
	}
	return s;
}

float parseValue(string str) {

	char ch[100];
	strcpy_s(ch, str.c_str());

	str = removeSpaces(ch);
	string temp;

	temp = str[0];
	int a = stoi(temp);

	temp = str[2];
	int b = stoi(temp);

	switch (str[1]) {
	case '+': {
		return a + b;
	}
	case '-': {
		return  a - b;
	}
	case '*': {
		return a * b;
	}
	case '/': {
		if ((a == 0) || (b == 0)) {
			throw invalid_argument("Can't divide by 0");
		}
		return a / b;
	}
	}

}

int main()
{

	// task #1 catch exceptions in divide function
	cout << "Task #1" << endl;
	int number = {};

	cout << "Input number ";
	cin >> number;
	try {
		cout << divide(number);
	}
	catch (const exception& e) {
		cerr << e.what();
	}

	//task #2 use custom exception
	cout << endl << "Task #2" << endl;
	string file = {};

	cout << "Input file name ";
	cin >> file;
	try {
		cout << openFile(file);
	}
	catch (const exception& e) {
		cerr << e.what();
	}

	//Task #3 parse simple arithmetic string
	cout << endl << "Task #3" << endl;
	string str;

	cin >> str;
	try {
		cout << parseValue(str);
	}
	catch (const exception& e) {
		cerr << e.what();
	}
}