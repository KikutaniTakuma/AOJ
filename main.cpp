#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <array>
#include <string>

class Dice {
public:
	Dice():
		nums(),
		currentTop(0llu)
	{}
	Dice(Dice&) = default;
	Dice(Dice&&) = default;
	~Dice() = default;


	Dice& operator=(const Dice&) = default;
	Dice& operator=(Dice&&) = default;

public:
	void Move(const std::string& move) {
		for (auto& i : move) {
			if (i == 'N') {

			}
			else if (i == 'S') {

			}
			else if (i == 'W') {

			}
			else if (i == 'E') {

			}
		}
	}

public:
	void Set(uint32_t num, size_t index) {
		nums[index] = num;
	}

private:
	std::array<uint32_t, 6> nums;
	size_t currentTop;
};


int main() {

	return 0;
}