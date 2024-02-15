#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>

int main() {
	int x, y;

	cin >> x >> y;

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
	size_t count = 0;
	for (auto & i : data) {
		
	}

	return 0;
}