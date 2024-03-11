#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

int main() {
	double a, b, C;

	cin >> a >> b >> C;
	C *= M_PI / 180.0;

	double S, L, H;

	S = 0.5 * a * b * std::sin(C);

	L = std::sqrt(a * a + b * b - 2.0 * a * b * std::cos(C)) + a + b;

	H = b * std::sin(C);

	cout << std::fixed << S << endl << L << endl << H;


	return 0;
}