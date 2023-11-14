#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Header.h"
#include <iostream>

void createAndSaveRandomArray(const std::string& filename, int size) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл для записи." << std::endl;
        return;
    }

    std::srand(time(nullptr));

    for (int i = 0; i < size; i++) {
        int random_number = std::rand() % 100;
        file << random_number << (i < size - 1 ? " " : "");
    }

    file.close();
}

int main() {
    const std::string filename = "data.txt";
    createAndSaveRandomArray(filename, 10);

    arraySanitizer sanitizer;
    sanitizer.loadFromFile(filename);

    std::cout << "Исходный массив: ";
    sanitizer.printArray();

    std::cout << "Минимальное значение: " << sanitizer.findMin() << std::endl;
    std::cout << "Максимальное значение: " << sanitizer.findMax() << std::endl;
    std::cout << "Среднее значение: " << sanitizer.findAverage() << std::endl;
    std::cout << "Количество элементов больше 30: " << sanitizer.countGreaterThan(30) << std::endl;

    return 0;
}
