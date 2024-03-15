#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cmath>
#include <vector>


int main() {
	int num = 0;
	
	cin >> num;

	std::vector<double> data;
	std::vector<double> data2;

	double input = 0.0;

	for (int i = 0; i < num; i++) {
		cin >> input;

		data.push_back(input);
	}

	for (int i = 0; i < num; i++) {
		cin >> input;

		data2.push_back(input);
	}

	double result = 0.0;

	for (int i = 1; i <= 3; i++) {
		result = 0.0;

		for (int j = 0; j < num; j++) {
			result += std::pow(std::abs(data[j] - data2[j]), static_cast<double>(i));
		}
		result = std::pow(result, 1.0 / static_cast<double>(i));

		cout << std::fixed << result << endl;
	}


	result = std::abs(data.front() - data2.front());
	for (int i = 1; i < num; i++) {
		result = std::max(result, std::abs(data[i] - data2[i]));
	}

	cout << std::fixed << result << endl;

	return 0;
}