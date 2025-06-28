#include <string>
#include <vector>

using namespace std;

string solution(int q, int r, string code) {
    string answer = "";
    
    int len = code.length() / q;
    if (code.length() % q > r) len++;
    answer.reserve(len);
    
    for (int i = 0; i < len; i++) {
        answer += code[i * q + r];
    }
    
    return answer;
}