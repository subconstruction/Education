#include <iostream>
#include <vector>
#include <ctime>

short genN(short min, short max) {return rand() % (max - min + 1) + min;}
const bool searchForElement(const std::vector<short> &vector, short element) {
    for (short n : vector) {
        if (n == element) return true;
    }

    return false;
}

int main() {
    srand((unsigned short)time(NULL));
    
    std::vector<short> newVec;

    while (true) {
        if (newVec.size() == 10) break;
        unsigned short num = genN(10, 25);

        if (searchForElement(newVec, num)) {
            printf("Skipped [%d] ~ found in vector<short>\n", num);
            continue;
        }

        newVec.push_back(num);

        printf("Added [%d] to vector, now vector<short> = { ", num);
        for (short i : newVec) {
            printf(" %d", i);
        }

        std::cout << " }" << std::endl;
    }

    return 0;
}