#include <iostream>;

const char* arr[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int main() {
	unsigned int input;

	std::cin >> input;
	std::cout << arr[input - 1];
}
