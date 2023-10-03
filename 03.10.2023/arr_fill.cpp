#include <iostream>
#include <vector>
#include <ctime>

int genN(int min, int max) {return rand() % (max - min + 1) + min;}
const bool searchForElement(const std::vector<int> &vector, int element) {
    for (int n : vector) {
        if (n == element) return true;
    }

    return false;
}

int main() {
    srand((unsigned int)time(NULL));
    
    std::vector<int> newVec;

    while (true) {
        if (newVec.size() == 10) break;
        unsigned int num = genN(10, 25);

        if (searchForElement(newVec, num)) {
            printf("Skipped [%d] ~ found in vector<int>\n", num);
            continue;
        }

        newVec.push_back(num);

        printf("Added [%d] to vector, now vector<int> = { ", num);
        for (int i : newVec) {
            printf(" %d", i);
        }

        std::cout << " }" << std::endl;
    }

    return 0;
}