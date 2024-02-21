#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
#include <vector>

int main() {
	std::vector<std::string> data;
	std::string input;
	input.clear();

	while (true) {
		cin >> input;

		if(atoi(input.c_str()) == 0) {
			break;
		}

		data.push_back(input);

		input.clear();

	}

	std::vector<int> result;
	for (auto& i : data) {
		int sum = 0;
		for (char& c : i) {
			sum += c - '0';
		}

		result.push_back(sum);
	}

	for (auto& i : result) {
		cout << i << endl;
	}

	return 0;
}