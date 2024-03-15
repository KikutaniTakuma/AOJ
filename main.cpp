#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cmath>
#include <vector>

int main() {
	double num = 0.0;
	std::vector<double> data;
	do {
		data.clear();
		cin >> num;

		if (num == 0.0) {
			break;
		}

		double sum = 0.0;
		double avg = 0.0;
		double dispersion = 0.0;
		double input;

		for (int i = 0; i < static_cast<int>(num); i++) {
			cin >> input;
			data.push_back(input);
			sum += input;
		}

		avg = sum / num;

		for (auto& i : data) {
			dispersion += std::pow(i - avg, 2.0);
		}

		dispersion /= num;

		cout << std::sqrt(dispersion) << endl;


	} while (num != 0);

	return 0;
}