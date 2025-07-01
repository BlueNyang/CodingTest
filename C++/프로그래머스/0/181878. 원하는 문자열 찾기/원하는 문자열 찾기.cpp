#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

inline int process(unsigned char c) {
    return tolower(c);
}

int solution(string myString, string pat) {
    transform(myString.begin(), myString.end(), myString.begin(), process);
    transform(pat.begin(), pat.end(), pat.begin(), process);
    
    if (myString.find(pat) != string::npos) return 1;
    return 0;
}