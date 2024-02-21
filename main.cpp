#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <array>
#include <string>

class Data {

private:
	char upperC = static_cast<char>(0);
	char lowerC = static_cast<char>(0);

	int count = 0;

public:
	bool operator==(const Data& right) const {
		return this->upperC == right.upperC && this->lowerC == right.lowerC;
	}
	bool operator!=(const Data& right) const {
		return not (*this == right);
	}

public:
	void CountUp() {
		count++;
	}

	const int& GetCount() const {
		return count;
	}

public:
	void SetChar(char c) {
		if (not std::isalpha(c)) {
			return;
		}

		if (std::isupper(c)) {
			upperC = c;
			lowerC = std::tolower(c);
		}
		else {
			upperC = std::toupper(c);
			lowerC = c;
		}
	}

	bool IsEqual(char c) {
		return c == upperC || c == lowerC;
	}

public:
	void Draw() {
		cout << lowerC << " : " << count << endl;
	}
};

int main() {
	std::array<Data, 26llu> data;

	char startC = 'A';


	for (char i = startC; i < static_cast<char>(data.size()) + startC; i++) {
		data[i - startC].SetChar(i);
	}

	std::string input;

	std::string inputData;

	while (cin >> input) {
		inputData += input;
	}

	for (char& i : inputData) {
		for (auto& j : data) {
			if (j.IsEqual(i)) {
				j.CountUp();
			}
		}
	}

	for (auto& i : data) {
		i.Draw();
	}


	return 0;
}