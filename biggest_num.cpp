#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

int main() {
    srand(static_cast<unsigned>(time(0)));

    const int numNumbers = 5;
    const int maxStringLength = 100000;

    std::vector<std::string> numberStrings;
    std::vector<char> maxDigits;
    std::vector<int> maxDigitIndices;

    for (int i = 0; i < numNumbers; i++) {
        std::string numberString;
        const int stringLength = rand() % maxStringLength + 1;

        for (int j = 0; j < stringLength; j++) {
            int randomNumber = rand() % 10;
            numberString += std::to_string(randomNumber);
        }

        numberStrings.push_back(numberString);

        char maxDigit = '0';
        int maxDigitIndex = 0;

        for (int j = 0; j < numberString.length(); j++) {
            if (numberString[j] > maxDigit) {
                maxDigit = numberString[j];
                maxDigitIndex = j;
            }
        }

        maxDigits.push_back(maxDigit);
        maxDigitIndices.push_back(maxDigitIndex);
    }

    for (int i = 0; i < numNumbers; i++) {
        std::cout << "Biggest Number: " << maxDigits[i] << std::endl;
        std::cout << "Index Of the Biggest: " << maxDigitIndices[i] << std::endl;
    }

    return 0;
}
