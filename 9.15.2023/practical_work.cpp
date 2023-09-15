#include <iostream>
#include <string>

using namespace std;

int main() {
    string iter;

    int tableSize = 10;

    for (int i = 2; i <= tableSize; ++i) {

        for (int j = 1; j <= 10; ++j) {
            int result = i * j;

            if (i == 2 && j == 2) {
                iter = "2x2=" + to_string(result);
            }

            cout << i << " x " << j << " = " << result << "\n";
        }

        cout << "\n";
    }

    cout << "My iteration => " << iter;
    return 0;
}
