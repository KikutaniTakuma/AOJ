#include <iostream>
#include <vector>

int main(void) {
    int num;
    std::cin >> num;

    std::vector<int> data;
    data.resize(num);

    for (auto& i : data) {
        std::cin >> i;
    }


	uint32_t GetRight(uint32_t top, uint32_t front) const {
		auto findNum = [this](uint32_t num) {
			size_t index = 0;

			for (auto& i : data) {
				if (i.num == num) {
					return index;
				}
				else {
					index++;
				}
			}

			return index;
			};

		size_t topIndex = findNum(top);
		size_t frontIndex = findNum(front);

		Vector3 right = data[frontIndex].direction.Cross(data[topIndex].direction).Normalize();

		size_t index = GetNumberFromDirection(right);

		return data[index].num;
	}

	bool IsSame(const Dice& other) {
		const auto&& otherArr = other.GetArray();
		auto same = [this, &otherArr]()->bool {
			return this->GetArray() == otherArr;
			};
		auto yRotateSame = [this, &same]()->bool {
			for (int i = 0; i < 4; i++) {
				if (same()) {
					return true;
				}
				else {
					Move("R");
				}
			}
			return false;
			};

		// xŽ²•ûŒü‚É‰ñ“]‚³‚¹‚é
		for (int i = 0; i < 4; i++) {
			if (same()) {
				return true;
			}
			else {
				// yŽ²‚ÅˆêŽü
				if (yRotateSame()) {
					return true;
				}
				Move("N");
			}
		}

		// ˆÈ‰ºxŽ²‚¶‚á‘«‚è‚È‚¢•ª
		Move("W");
		// yŽ²‚ÅˆêŽü
		if (yRotateSame()) {
			return true;
		}
		Move("EE");
		// yŽ²‚ÅˆêŽü
		if (yRotateSame()) {
			return true;
		}
		Move("W");

		return false;
	}


private:
	size_t GetNumberFromDirection(const Vector3& direction)const {
		size_t result = 0;

		for (auto& i : data) {
			if (direction == i.direction) {
				break;
			}
			else {
				result++;
			}
		}

		return result;
	}

	size_t GetCurrentTop()    const {
		return GetNumberFromDirection(Vector3::kYIdentity);
	}
	size_t GetCurrentBottom() const {
		return GetNumberFromDirection(-Vector3::kYIdentity);
	}
	size_t GetCurrentRight()  const {
		return GetNumberFromDirection(Vector3::kXIdentity);
	}
	size_t GetCurrentLeft()   const {
		return GetNumberFromDirection(-Vector3::kXIdentity);
	}
	size_t GetCurrentBack()   const {
		return GetNumberFromDirection(Vector3::kZIdentity);
	}
	size_t GetCurrentFront()  const {
		return GetNumberFromDirection(-Vector3::kZIdentity);
	}

	std::array<uint32_t, 6> GetArray() const {
		std::array<uint32_t, 6> result = {
			data[GetCurrentTop()   ].num,
			data[GetCurrentBottom()].num,
			data[GetCurrentRight() ].num,
			data[GetCurrentLeft()  ].num,
			data[GetCurrentBack()  ].num,
			data[GetCurrentFront() ].num
		};

		return result;
	}

public:
	void Set(uint32_t num) {
		data[index].num = num;
		index++;
	}

private:
	std::array<Data, 6> data;
	size_t index;
};


int main() {
	std::vector<Dice> data;
	size_t size = 0;
	cin >> size;
	data.resize(size);

	for (auto& dice : data) {
		for (size_t i = 0; i < 6; i++) {
			uint32_t input;
			cin >> input;
			dice.Set(input);
		}
	}

	bool isSame = false;

	while (1 < data.size()) {
		auto back = --data.end();

		for (auto i = data.begin(); i != data.end(); i++) {
			if (i == back) {
				continue;
			}

			if (i->IsSame(*back)) {
				isSame = true;
				break;
			}
		}

		data.erase(back);
	}

    std::cout << count;

    return 0;
}