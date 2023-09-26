#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream tokenStream(str);
    std::string token;

    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    std::string input;
    double a,b,c,Root, Root2;

    std::cout << "Укажите a,b,c (используйте запятую как разделитель)" << "\n";
    std::cin >> input;
    
    std::vector<std::string> tokens = split(input, ',');

    a = std::stod(tokens[0]);
    b = std::stod(tokens[1]);
    c = std::stod(tokens[2]);

    std::cout << a;

    double discriminant = (b*b) - (4*a*c);

    if (discriminant < 0) {
        std::cout << "Discriminant is under 0";

        return 0;
    }

    Root = (-b + sqrt(discriminant)) / 2*a;
    Root2 = (-b - sqrt(discriminant)) / 2*a;

    printf("Discriminant -> %d | Root -> %d | Root2 -> %d", discriminant, Root, Root2);

    return 0;
}