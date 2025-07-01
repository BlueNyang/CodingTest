#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string my_string, string alp) {
    unsigned char gap = 'a' - 'A';
    
    for (char& c: my_string) {
        if (c == alp[0]) c -= gap;
    }
    
    return my_string;
}