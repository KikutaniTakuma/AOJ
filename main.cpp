#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cmath>


int main() {
	double x, y;
	double x1, y1;

	cin >> x >> y >> x1 >> y1;

	cout << std::fixed << std::sqrt(pow(y - y1, 2.0) + pow(x - x1, 2.0)) << endl;


	return 0;
}