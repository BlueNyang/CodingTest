#include <string>
#include <vector>
#include <iostream>

using namespace std;

inline void add(int& a, int& b, bool add) { add ? a += b : a -= b; }

int solution(string my_string) {
    int answer = 0, temp = 0;
    bool is_add = true;
    
    for (const auto& c: my_string) {
        if (c >= '0' && c <= '9') {
            temp *= 10;
            temp += static_cast<int>(c - '0');
        }
        else if (c == '+') is_add = true;
        else if (c == '-') is_add = false;
        
        else if (c == ' ' && temp != 0){
            is_add ? answer += temp : answer -= temp;
            temp = 0;
        }
    }
    
    is_add ? answer += temp : answer -= temp;
    
    return answer;
}