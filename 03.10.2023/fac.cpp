#include <iostream>

unsigned long long factorial(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    unsigned int n;

    std::cin >> n;

    try {
        if (n < 0) {
            std::cout << "Input value couldn\t be negative";
            return 0;
        }

        unsigned long long result = factorial(n);
        std::cout << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
