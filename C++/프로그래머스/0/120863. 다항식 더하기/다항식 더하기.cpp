#include <string>

using namespace std;

string solution(string polynomial) {
    int x = 0, constant = 0;
    int temp = 0;
    bool __PASS_FLAG__ = false;
    
    for (const auto p: polynomial) {
        if (p >= '0' && p <= '9') {
            temp *= 10;
            temp += p - '0';
            __PASS_FLAG__ = false;
        }
        
        if (p == 'x') {
            if (temp == 0) x += 1;
            else x += temp;
            temp = 0;
            __PASS_FLAG__ = true;
        }
        
        if (p == '+' && !__PASS_FLAG__) {
            if (temp != 0) constant += temp;
            temp = 0;
        }
    }
    
    if (temp != 0) constant += temp;
    
    string answer = "";
    
    if (x != 0) {
        if (x == 1) answer = "x";
        else answer = to_string(x) + "x";
    }
    
    if (constant != 0) {
        if (answer != "") answer += " + ";
        answer += to_string(constant);
    }
    
    
    return answer;
}