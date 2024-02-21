#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>

int main() {
	std::string s;
	std::string p;

	cin >> s >> p;

	cout << (p.find(p) == std::string::npos) ? "Yes" : "No";

	return 0;
}