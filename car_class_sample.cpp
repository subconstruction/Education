#include <iostream>

class Car {
    unsigned short initionState = 1;
private:
    void startIgnition() {
        std::cout << "Зажигание включено." << std::endl;
        initionState = 2;
    }

    void turnOnMultimedia() {
        std::cout << "Мультимедийная система включена." << std::endl;
        initionState = 3;
    }

    void activateAirConditioning() {
        std::cout << "Кондиционер включен." << std::endl;
        initionState = 4;
    }
    
public:
    void startCar() {
        startIgnition();
        turnOnMultimedia();
        activateAirConditioning();

        std::cout << "Автомобиль запущен." << std::endl;
        initionState = 0;
    }
    
    ~Car() {
        std::cout << "Автомобиль заглушен" << std::endl;
        std::cout << "Inition State: " << initionState << std::endl;
    }
};

int main() {
    Car myCar;
    myCar.startCar();
    
    return 0;
}
