#include <iostream>
#include <vector>

using std::cout;

void shakerSort(std::vector<int>& arr) {
    bool swapped;
    size_t n = arr.size();
    
    do {
        swapped = false;
        
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        
        if (!swapped) {
            break;
        }

        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

int main() {
    std::vector<int> arr = {9, 55, 2, 2, 4, 26, 67, 1, 7, 4, 7, 83, 645, 234, 23, 564, 34, 12};

    shakerSort(arr);

    cout << "Sorted array: ";
    
    for (int num : arr) {
        cout << num << "\t";
    }

    return 0;
}
