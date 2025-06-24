#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string str) {
    const char gap = 'a' - 'A';
    
    for (char& c: str) {
        if (c >= 'A' && c <= 'Z') c += gap;
    }
    
    sort(str.begin(), str.end());
    return str;
}