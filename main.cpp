#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
#include <vector>

int main() {
	std::vector<std::string> data;
	std::string input;


	do {
		cin >> input;

		data.push_back(input);

	} while(atoi(data.back().c_str()) == 0);

	std::vector<int> result;
	for (auto& i : data) {
		int sum = 0;
		for (char& c : i) {
			sum += atoi(&c);
		}

		result.push_back(sum);
	}

	for (auto& i : result) {
		cout << i << endl;
	}

	return 0;
}