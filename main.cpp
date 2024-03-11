#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
#include <string>

int main() {
	std::vector<std::string> taro;
	std::vector<std::string> hanako;


	int taroPoint = 0;
	int hanakoPoint = 0;

	int count = 0;
	cin >> count;

	std::string input;
	std::string input2;

	for (int i = 0; i < count;i++) {
		cin >> input >> input2;

		taro.push_back(input);
		hanako.push_back(input2);
	}

	for (size_t i = 0; i < count; i++) {
		if (hanako[i] < taro[i]) {
			taroPoint += 3;
		}
		else if (taro[i] == hanako[i]) {
			taroPoint += 1;
			hanakoPoint += 1;
		}
		else {
			hanakoPoint += 3;
		}
	}

	cout << taroPoint << " " << hanakoPoint << endl;

	return 0;
}