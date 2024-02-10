#include <iostream>
using std::cout;
using std::endl;
using std::cin;


int main() {
	int n, x;

	while (true) {
		cin >> n >> x;
		if ((n == 0) && (x == 0)) {
			break;
		}

		int count = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					break;
				}
				for (int k = 1; k <= n; k++) {
					if ((i == k) || (j == k)) {
						break;
					}

					if ((i + j + k) == x) {
						count++;
					}

				}
			}
		}

		cout << count << endl;

	};

	return 0;
}