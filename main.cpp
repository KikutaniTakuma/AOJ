#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
#include <algorithm>

int main() {
	std::string str;
	std::string function;

	int a;
	int b;

	std::string replaceStr;
	std::string input;
	std::string procNum;

	cin >> str;

	while (cin >> input >> procNum);
	{
		str = input;


		for (int i = 0; i < std::atoi(procNum.c_str());i++) {
			if (input == "replace") {
				cin >> a >> b >> replaceStr;
				auto itr = str.begin();
				str.replace(itr + a, itr + b, replaceStr);
			}
			else if (input == "reverse") {
				cin >> a >> b;

				auto itr = str.begin();
				std::string reverseTmp;

				std::copy(itr + a, itr + b, reverseTmp.begin());

				std::reverse(reverseTmp.begin(), reverseTmp.end());

				str.replace(itr + a, itr + b, reverseTmp);
			}
			else if (input == "print") {
				cin >> a >> b;

				auto itr = str.begin();

				std::string tmp;

				std::copy(itr + a, itr + b, tmp.begin());

				cout << tmp << endl;
			}
		}
	}



	return 0;
}