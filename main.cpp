#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
#include <vector>

class Data {
public:
	void SetShuffleNumber(const std::string& str) {
		shuffle_.push_back(std::atoi(str.c_str()));
	}

	void SetStr(const std::string& str) {
		str_ = str;
	}

	void Shuffle() {
		for (auto& i : shuffle_) {
			for (size_t j = 0; j < i; j++) {
				char tmp = str_.front();
				str_.erase(str_.begin());
				str_ += tmp;
			}
		}
	}

	void Draw() {
		cout << str_ << endl;
	}

	void Reset() {
		str_.clear();
		shuffle_.clear();
	}

private:
	std::string str_;

	std::vector<int32_t> shuffle_;
};

int main() {
	std::string input;
	std::vector<Data> data;
	while (std::getline(cin, input)) {
		if (input == "-") {
			break;
		}

		for (const char& i : input) {
			if (not std::isalpha(i)) {

				break;
			}
		}
	}


	return 0;
}