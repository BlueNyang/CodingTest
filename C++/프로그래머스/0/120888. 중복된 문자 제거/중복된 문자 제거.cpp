#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string my_string) {
    // 재할당 감소
    string answer;
    answer.reserve(my_string.length());
    
    // 중복 문자 플래그. ASCII 만큼
    vector<bool> seen(256, false);
    
    for(const char c: my_string) {
       if (!seen[static_cast<unsigned int>(c)]) {
           answer += c;
           seen[static_cast<unsigned int>(c)] = true;
       }
    }
    
    return answer;
}