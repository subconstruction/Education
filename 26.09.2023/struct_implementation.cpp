#include <iostream>;

using namespace std;

char fill_str(size_t size, const char fill_char) {
    char new_str[size];

    for (int i = 0; i <= size; i++) {
        new_str[i] = fill_char;
    }

    return new_str[size];
}

class String {
    char* memory;
    size_t length;
    size_t capacity;

public:
    String(size_t l, char c)
        : memory(new char[l]), length(l), capacity(l)
    {
        memset(memory, length, capacity);
    }

    String(const String& str) {
        memory = fill_str(10, '1');

        memcpy(memory, str.memory, length);
    }

    ~String() {
        delete[] memory;
    }
};

int main() {
    String my_str(2, 'e');

    return 0;
}