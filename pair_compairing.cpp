#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0)));

    short array[100];
    short count = 0;
    
    vector<std::pair<short, short>> storage;

    for (short i = 0; i < 100; ++i) {
        array[i] = rand() % 10001 - 5000;
    }

    for (short i = 0; i < 50; ++i) {
        if ((array[i] + array[99 - i]) % 2 != 0 && (array[i] + array[99 - i]) > 0) {
            count++;
            
            short firstValue = array[i];
            short secondValue = array[99 - i];
            storage.push_back(std::make_pair(firstValue, secondValue));
        }
    }
    
    for (const auto& pair : storage) {
        std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
    }

    cout << "Pairs count: " << count << endl;

    return 0;
}
