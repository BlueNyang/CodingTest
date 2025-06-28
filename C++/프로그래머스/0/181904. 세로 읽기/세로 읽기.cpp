#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) {
    string answer = "";
    
    int len = my_string.length() / m;
    answer.reserve(len);
    
    for (int i = 0; i < len; i++) {
        answer += my_string[i * m + c - 1];
    }
    
    return answer;
}