#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> split(const std::string& str, char separator) {
    std::vector<std::string> inputVector;
    std::istringstream inputStream(str);
    std::string inputString;

    while (std::getline(inputStream, inputString, separator)) {
        inputVector.push_back(inputString);
    }

    return inputVector;
}

int main() {
    std::string input;
    double a,b,c,Root, Root2;

    std::cout << "Укажите a,b,c (используйте запятую как разделитель)" << "\n";
    std::cin >> input;
    
    std::vector<std::string> inputVector = split(input, ',');

    a = std::stod(inputVector[0]);
    b = std::stod(inputVector[1]);
    c = std::stod(inputVector[2]);

    double discriminant = (b*b) - (4*a*c);

    if (discriminant < 0) {
        std::cout << "Discriminant is under 0";

        return 0;
    }

    Root = (-b + sqrt(discriminant)) / 2*a;
    Root2 = (-b - sqrt(discriminant)) / 2*a;

    printf("Discriminant -> %f | Root -> %f | Root2 -> %f", discriminant, Root, Root2);

    return 0;
}