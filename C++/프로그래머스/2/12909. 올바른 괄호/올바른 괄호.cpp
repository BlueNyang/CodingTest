#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int count = 0;
    
    for (const char c: s) {
        if (c == '(') ++count;
        if (c == ')') {
            if (--count < 0) return false;
        }
    }
    return count == 0;
}