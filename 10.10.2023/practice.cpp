#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using std::cout;

void generateRandomArray(std::vector<int> &arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr.push_back(std::rand());
    }
}

void shakerSort(std::vector<int>& arr) {
    bool swapped;
    size_t n = arr.size();

    int left = 0;
    int right = n - 1;
    int lastSwapped = right;

    do {
        swapped = false;

        for (int i = left; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
                lastSwapped = i;
            }
        }

        right = lastSwapped;

        if (!swapped) {
            break;
        }

        swapped = false;

        for (int i = right - 1; i >= left; --i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
                lastSwapped = i;
            }
        }

        left = lastSwapped + 1;

    } while (swapped);
}

int main() {
    const int arraySize = 100;
    std::vector<int> arr;

    std::srand(std::time(nullptr));
    generateRandomArray(arr, arraySize);
    
    double start, end;
    start = clock();
    shakerSort(arr);
    end = clock();

    std::cout << "Sorted array: ";
    
    for (int num : arr) {
        std::cout << num << "\t";
    }
    
    std::cout << "\n[Sort] Runtime: " << end - start << "ms" << std::endl;

    return 0;
}
