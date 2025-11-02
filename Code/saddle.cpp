//
// Created by 易治行 on 2025/11/2.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

struct Coordinate {
    int x;
    int y;
};

std::vector<Coordinate> getSaddle(int n, const std::vector<std::vector<int>>& a);
std::vector<int> getMinValueRow(int n, const std::vector<std::vector<int>>& a);
std::vector<int> getMaxValueCol(int n, const std::vector<std::vector<int>>& a);

int main(void) {
    srand(time(0));
    int n;

    std::cout << "Enter n: " ;
    std::cin >> n;

    std::vector<std::vector<int>> a(n, std::vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 100;
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    auto saddles = getSaddle(n, a);

    if (saddles.empty())
        std::cout << "No saddle points found." << std::endl;
    else {
        for (auto saddle: saddles)
            std::cout << "(" << saddle.x << ", " << saddle.y << ")" << std::endl;
    }

    return 0;
}

std::vector<Coordinate> getSaddle(int n, const std::vector<std::vector<int>>& a) {
    std::vector<Coordinate> saddles;

    auto minValueRow = getMinValueRow(n, a);
    auto maxValueCol = getMaxValueCol(n, a);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == minValueRow[i] && a[i][j] == maxValueCol[j]) {
                saddles.push_back(Coordinate{i, j});
            }
        }
    }

    return saddles;
}

std::vector<int> getMinValueRow(int n, const std::vector<std::vector<int>>& a) {
    std::vector<int> minValueRow;

    for (int i = 0; i < n; i++) {
        int minValue = a[i][0];

        for (int j = 1; j < n; j++)
            minValue = minValue < a[i][j] ? minValue : a[i][j];

        minValueRow.push_back(minValue);
    }

    return minValueRow;
}

std::vector<int> getMaxValueCol(int n, const std::vector<std::vector<int>>& a) {
    std::vector<int> maxValueCol;

    for (int j = 0; j < n; j++) {
        int maxValue = a[0][j];

        for (int i = 1; i < n; i++)
            maxValue = maxValue > a[i][j] ? maxValue : a[i][j];

        maxValueCol.push_back(maxValue);
    }

    return maxValueCol;
}