#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>

int main() {
	std::string input;
	size_t count;
	while (true) {
		std::cin >> input >> count;

		if (input == "-") {
			break;
		}

		for (size_t i = 0; i < count; i++) {
			int shuffle = 0;
			std::cin >> shuffle;

			for (int j = 0; j < shuffle;j++) {
				char tmp = input.front();
				input.erase(input.begin());
				input += tmp;
			}
		}

		cout << input << endl;
	}

	return 0;
}