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


    size_t count = 0;
    bool isBreak = false;
    for (int n = 1; n <= num; n++) {
        for (size_t i = 0; i < data.size(); i++) {
            if (n == data[i]) {
                for (size_t j = i + 1; j < data.size(); j++) {
                    if (n == data[j]) {
                        isBreak = true;
                        break;
                    }
                    count++;
                }
                if (isBreak) {
                    isBreak = false;
                    break;
                }
            }
        }
    }

    std::cout << count;

    return 0;
}