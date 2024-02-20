#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>


int main() {
	size_t n,m,l;

	cin >> n >> m >> l;

	std::vector<std::vector<size_t>> matA;
	std::vector<std::vector<size_t>> matB;

	matA.resize(n);
	for (auto& i : matA) {
		i.resize(m);
	}
	matB.resize(m);
	for (auto& i : matB) {
		i.resize(l);
	}


	for (auto& i : matA) {
		for (auto& j : i) {
			cin >> j;
		}
	}
	for (auto& i : matB) {
		for (auto& j : i) {
			cin >> j;
		}
	}

	std::vector<std::vector<size_t>> matC;

	matC.resize(n);
	for (auto& i : matC) {
		i.resize(l);
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < l; x++) {
			for (int i = 0; i < m; i++) {
				matC[y][x] += matA[y][i] * matB[i][x];
			}
		}
	}


	for (auto& i : matC) {
		for (size_t j = 0; j < i.size();j++) {
			if (j == i.size() - 1) {
				cout << i[j] << "\n";
			}
			else {
				cout << i[j] << " ";
			}
		}
	}

	return 0;
}