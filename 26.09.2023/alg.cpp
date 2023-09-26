#include <iostream>

uint alg(uint a, uint b) {
    while (b != 0) {
        uint last_int = b;
        b = a % b;

        a = last_int;
    }

    return a;
}

int main() {
    unsigned int a, b, result;

    std::cout << "Введите a,b\n";
    std::cin >> a >> b;

    result = alg(a, b);
    std::cout << "НОД: " << result;

    return 0;
}
