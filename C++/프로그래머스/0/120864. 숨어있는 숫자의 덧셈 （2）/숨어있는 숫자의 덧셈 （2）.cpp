#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    int temp = 0;
    
    for(const auto c: my_string) {
        if (c >= '0' && c <= '9') {
            temp *= 10;
            temp += c - '0';
        }
        else if (temp != 0) {
            answer += temp;
            temp = 0;
        }
    }
    
    if (temp != 0) answer += temp;
    
    return answer;
}