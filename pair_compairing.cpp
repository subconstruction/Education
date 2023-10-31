#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0)));

    int array[100];
    int count = 0;

    for (int i = 0; i < 100; ++i) {
        array[i] = rand() % 10001 - 5000;
    }

    for (int i = 0; i < 50; ++i) {
        if ((array[i] + array[99 - i]) % 2 != 0 && (array[i] + array[99 - i]) > 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
