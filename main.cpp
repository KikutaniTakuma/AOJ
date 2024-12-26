#include <iostream>
#include <string>
#include <vector>

void CalcGoal(std::vector<std::string>& mapdata, int k) {
    for (int count = 0, y = 0; auto & i : mapdata) {
        // 1, 2, 5, 6, 9, 10, 13, 14...
        if (((y % 2 == 0) and (y % 4 != 0)) or ((y + 1 % 2 == 0) and (y + 1 % 4 != 0))) {
            for (auto j = i.rbegin(); j != i.rend(); j++) {
                if (*j == '.') {
                    count++;
                    if (count == k) {
                        *j = 'G';
                        return;
                    }
                }
            }
        }
        else {
            for (auto& j : i) {
                if (j == '.') {
                    count++;
                    if (count == k) {
                        j = 'G';
                        return;
                    }
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int k = 0;

    std::cin >> k;

    const int kMaxMapSize = 50;

    std::vector<std::string> mapdata(kMaxMapSize);
    mapdata.front() = "S";
    for (int i = 0; i < kMaxMapSize - 1; i++) {
        mapdata.front() += ".";
    }
    for (int i = 1; i < kMaxMapSize; i++) {
        // 1, 5, 9, 13...s–Ú
        if ((i - 1) % 4 == 0) {
            for (int j = 0; j < kMaxMapSize - 1; j++) {
                mapdata[i] += "#";
            }

            mapdata[i] += ".";
        }
        // 3, 7, 11, 15...s–Ú
        else if ((i + 1) % 4 == 0) {
            mapdata[i] += ".";
            for (int j = 1; j < kMaxMapSize; j++) {
                mapdata[i] += "#";
            }
        }
        else {
            for (int j = 0; j < kMaxMapSize; j++) {
                mapdata[i] += ".";
            }
        }
    }


    CalcGoal(mapdata, k);

    std::cout << kMaxMapSize << " " << kMaxMapSize << std::endl;

    for (auto& i : mapdata) {
        std::cout << i << std::endl;
    }

    return 0;
}
