#include <iostream>
#include <ctime>
#include <vector>

const bool isPrime(unsigned int n)
{
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0) return false;

    return true;
}

int Math(const std::string& method, std::vector<int>& arr) {
    static std::vector<int>* vector_ptr = nullptr;

    if (vector_ptr == nullptr) {
        vector_ptr = &arr;

        std::cout << "Math() has been initialized with: std::vector<int> { ";

        for (int num : arr) {
            std::cout << num << " ";
        }

        std::cout << "}\n\n";
    }

    int returnValue = arr[0];

    for (int num : *vector_ptr) {
        if (method == "min") returnValue = num < returnValue ? num : returnValue;
        else if (method == "max") returnValue = num > returnValue ? num : returnValue;
    }

    return returnValue;
}

int main() {
    std::vector<int> generatedVector;
    int primeCount = 0, numSum = 0, maxIter = 20;

    int64_t numMult = 1;

    srand(time(NULL));

    for (int i = 0; i < maxIter; i++) {
        unsigned int generatedNum = rand() % 101;

        if (isPrime(generatedNum)) primeCount++;

        numSum += generatedNum;
        numMult *= generatedNum;

        generatedVector.push_back(generatedNum);
    }

    printf("Prime Numbers Count: [%d] | Non-Prime Numbers Count: [%d] | Numbers Summ: [%d] | Numbers Product: [%u] | Minimum Number: [%d] | Maximum Number: [%d]", primeCount, maxIter - primeCount, numSum, numMult, Math("min", generatedVector), Math("max", generatedVector));

    return 0;
}
