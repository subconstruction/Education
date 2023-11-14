#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Header.h"

using namespace std;

void createAndSaveRandomArray(const string& filename, int size) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл для записи." << endl;
        return;
    }

    srand(time(nullptr));

    for (int i = 0; i < size; i++) {
        int random_number = rand() % 100;
        file << random_number << (i < size - 1 ? " " : "");
    }

    file.close();
}

int main() {
    const string filename = "data.txt";
    createAndSaveRandomArray(filename, 10);

    arraySanitizer sanitizer;
    sanitizer.loadFromFile(filename);

    cout << "Исходный массив: ";
    sanitizer.printArray();

    cout << "Минимальное значение: " << sanitizer.findMin() << endl;
    cout << "Максимальное значение: " << sanitizer.findMax() << endl;
    cout << "Среднее значение: " << sanitizer.findAverage() << endl;
    cout << "Количество элементов больше 30: " << sanitizer.countGreaterThan(30) << endl;

    return 0;
}
