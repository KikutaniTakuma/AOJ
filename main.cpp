#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>

int main() {
	int x, y;

	cin >> y >> x;

	std::vector<std::vector<int>> data;

	data.resize(y);
	for (auto& i : data) {
		i.resize(x);
	}

	for (auto& i : data) {
		for (auto& j : i) {
			cin >> j;
		}
	}

	for (auto& i : data) {
		int total = 0;
		for (auto& j : i) {
			total += j;
		}
		i.push_back(total);
	}

	data.push_back(std::vector<int>());
	auto& last = data.back();
	for (size_t count = 0; count < data.front().size() - 1; count++) {
		int sum = 0;
		for (size_t i = 0; i < data.size() - 1;i++) {
			sum += data[i][count];
		}

		last.push_back(sum);
	}

	int sum = 0;
	for (auto& i : last) {
		sum += i;
	}

	last.push_back(sum);

	for (auto& i : data) {
		for (size_t j = 0; j < i.size();j++) {
			if (j == i.size()-1) {
				cout << i[j] << "\n";
			}
			else {
				cout << i[j] << " ";
			}
		}
	}

	return 0;
}