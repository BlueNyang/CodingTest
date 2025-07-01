#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    for (char& c: myString) {
        if (c == 'A') ++c;
        else --c;
    }
    
    return static_cast<int>(myString.find(pat) != string::npos);
}