#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>

int main() {
	std::string s;
	std::string p;

	cin >> s >> p;

	std::string tmpS = s;

	do {
		if (s.find(p) != std::string::npos) {
			cout << "Yes"<< endl;
			return 0;
		}
		else {
			char firstCBuf = s.front();
			s.erase(s.begin());
			s += firstCBuf;
		}
	} while(tmpS != s);

	cout << "No" << endl;

	return 0;
}