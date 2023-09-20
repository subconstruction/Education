#include <iostream>
#include <ctime> 

using namespace std;

int main() 
{ 
    int i;

    srand((unsigned)time(NULL)); 
    i = (rand()%6)+1; 

    cout << i << "\n"; 
}