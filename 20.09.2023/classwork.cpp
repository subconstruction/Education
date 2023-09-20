#include <iostream>
#include <ctime> 

using namespace std;

int genN(int min, int max) {
    int i = (rand()%(max-min+1)+min);

    return i;
}

int doStackOverflow(int a) {
    return doStackOverflow(a);
}

int main() 
{ 
    doStackOverflow(2);
    srand((unsigned)time(NULL));

    for (int i=0;i<=10;i++) {
        cout << genN(10, 20) << "\n"; 
    }

    return 0;
}