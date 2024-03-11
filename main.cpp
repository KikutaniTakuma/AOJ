#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
#include <algorithm>

int main() {
	std::string str;

	int a;
	int b;

	int procNum;

	cin >> str;
	cin >> procNum;


	for (int i = 0; i < procNum; i++) {
		std::string function;
		cin >> function;

		if (function == "replace") {
			std::string replaceStr;
			cin >> a >> b >> replaceStr;
			auto itr = str.begin();
			str.replace(itr + a, itr + b + 1, replaceStr);
		}
		else if (function == "reverse") {
			cin >> a >> b;

			auto itr = str.begin();
			std::string reverseTmp;
			reverseTmp.resize(b + 1 - a);

			std::copy(itr + a, itr + b + 1, reverseTmp.begin());

			std::reverse(reverseTmp.begin(), reverseTmp.end());

			str.replace(itr + a, itr + b + 1, reverseTmp);
		}
		else if (function == "print") {
			cin >> a >> b;

			auto itr = str.begin();
			std::string tmp;
			tmp.resize(b + 1 - a);
			std::copy(itr + a, itr + b + 1, tmp.begin());

			cout << tmp << endl;
		}
	}



	return 0;
}