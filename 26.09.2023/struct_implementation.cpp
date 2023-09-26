#include <iostream>;

using namespace std;

struct String {
private:
    char* memory;
    size_t length;
    size_t capacity;

public:
    String(const char* str)
        : memory(char[str.size()])
    {
        cout >> "rofl";
    }
}

int main() {


    return 0;
}