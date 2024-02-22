#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>

int main() {
	std::string w;
	std::string T = "BEGIN_OF_TEXT";
	int count = 0;

	cin >> w;

	std::string tmpW;

	for (auto& i : w) {
		tmpW += std::tolower(i);
	}

	w = std::move(tmpW);

	while (T != "END_OF_TEXT") {
		cin >> T;

		std::string tmpT;
		for (auto& i : T) {
			tmpT += std::tolower(i);
		}

		if (tmpT == w) {
			count++;
		}
	}

	cout << count << endl;

	return 0;
}