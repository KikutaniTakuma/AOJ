#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

struct IslandData {
    int aroundSeaLength = 0;
    int area = 0;

    bool operator==(const IslandData& right) const {
        return area == right.area and aroundSeaLength == right.aroundSeaLength;
    }

    bool operator!=(const IslandData& right) const {
        return not (*this == right);
    }
};

enum Pre {
    UP,
    DOWN,
    RIGHT,
    LEFT,
    NONE
};

void ClaclIslandData(IslandData& output, std::vector<std::vector<bool>>& data, const std::vector<std::vector<bool>>& constdata, int x, int y, Pre pre) {
    data[y][x] = false;
    output.aroundSeaLength += (pre == NONE) ? 4 : 3;
    output.area += 1;

    // ã
    if (y + 1 < data.size() and pre != UP and constdata[y + 1][x]) {
        output.aroundSeaLength -= 1;
        if (data[y + 1][x]) {
            ClaclIslandData(output, data, constdata, x, y + 1, DOWN);
        }
    }
    // ‰º
    if (0<=y-1 and pre != DOWN and constdata[y - 1][x]) {
        output.aroundSeaLength -= 1;
        if (data[y - 1][x]) {
            ClaclIslandData(output, data, constdata, x, y - 1, UP);
        }
    }
    // ‰E
    if (x + 1 < data.front().size() and pre != RIGHT and constdata[y][x + 1]) {
        output.aroundSeaLength -= 1;
        if (data[y][x + 1]) {
            ClaclIslandData(output, data, constdata, x + 1, y, LEFT);
        }
    }
    // ¶
    if (0 <= x - 1 and pre != LEFT and constdata[y][x -1]) {
        output.aroundSeaLength -= 1;
        if (data[y][x - 1]) {
            ClaclIslandData(output, data, constdata, x - 1, y, RIGHT);
        }
    }
}

int main(void) {
    int h = 0;
    int w = 0;

    std::cin >> h >> w;
    std::vector<std::vector<bool>> data;
    data.resize(h);
    for (auto& i : data) {
        i.resize(w);
    }

    std::vector<IslandData> islanddata;

    // “ü—Í‚ğó‚¯æ‚é
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char input;
            std::cin >> input;
            if (input == '#') {
                data[i][j] = true;
            }
        }
    }

    auto constData = data;

    // “ü—Í‚©‚ç“‡‚ğì‚é
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (data[i][j]) {
                islanddata.emplace_back(IslandData());
                ClaclIslandData(islanddata.back(), data, constData, j,i,NONE);
            }
        }
    }

    std::sort(islanddata.begin(), islanddata.end(), [](const IslandData& a, const IslandData& b) {
        return a.area != b.area ? a.area > b.area : a.aroundSeaLength > b.aroundSeaLength;
        });


    for (auto& i : islanddata) {
        std::cout << i.area << " " << i.aroundSeaLength << std::endl;
    }


    return 0;
}