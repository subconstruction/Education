#ifndef Header_h
#define Header_h

#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>

class arraySanitizer {
private:
    std::vector<int> array;

public:
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Не удалось открыть файл для чтения." << std::endl;
            return;
        }

        int value;
        while (file >> value) {
            array.push_back(value);
        }
        file.close();
    }

    const int findMin() {
        if (array.empty()) return INT_MIN;
        return *std::min_element(array.begin(), array.end());
    }

    const int findMax() {
        if (array.empty()) return INT_MIN;
        return *std::max_element(array.begin(), array.end());
    }

    const double findAverage() {
        if (array.empty()) return 0.0;
        return std::accumulate(array.begin(), array.end(), 0.0) / array.size();
    }

    const int countGreaterThan(int value) {
        return std::count_if(array.begin(), array.end(), [value](int elem){ return elem > value; });
    }

    const void printArray() {
        for (int num : array) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};


#endif
