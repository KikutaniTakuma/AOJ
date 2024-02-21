#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
#include <vector>

char ChangeCharScale(char c) {
	if (not ('a' <= c && c <= 'z') && 
		not ('A' <= c && c <= 'Z')
		) {
		return c;
	}

	const int toSmallChar = static_cast<int>('a') - static_cast<int>('A');
	const int bigCharMax = static_cast<int>('Z');

	const int cInt = static_cast<int>(c);

	if (bigCharMax < cInt) {
		return static_cast<char>(cInt - toSmallChar);
	}
	else {
		return static_cast<char>(cInt + toSmallChar);
	}
}


int main() {
	std::string input;

	std::getline(cin, input);

	std::string result;

	for (char& i : input) {
		result += ChangeCharScale(i);
	}

	cout << result << endl;

	return 0;
}