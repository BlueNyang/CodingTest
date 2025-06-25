#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    char gap = 'a' - 'A';
    
    for (char& c: str) {
        if (c >= 'A' && c <= 'Z') c += gap;
        else c -= gap;
    }
    
    cout << str << endl;
    
    return 0;
}