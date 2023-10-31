#include <iostream>
#include <ctime> 

using namespace std;

int genN(int min, int max) {
    int i = (rand()%(max-min+1)+min);

    return i;
}

int doStackOverflow(int* a) {
    cout << *a;

    return doStackOverflow(a);
}

int main() 
{
    int cool_int = 2;
    int* cool_ptr = &cool_int;

    reinterpret_cast<int32_t> (cool_int);

    cout << cool_int << endl;

    //doStackOverflow(cool_ptr);
    srand((unsigned)time(NULL));

    for (int i=0;i<=10;i++) {
        cout << genN(10, 20) << "\n"; 
    }

    return 0;
}