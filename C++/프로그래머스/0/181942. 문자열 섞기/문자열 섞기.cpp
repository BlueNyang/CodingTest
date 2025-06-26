#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    const int len = str1.length();
    if (len != str2.length()) return "";
    
    string answer;
    answer.reserve(len * 2);
    
    for (int i = 0; i < len; i++) {
        answer += str1[i];
        answer += str2[i];
    }
    
    return answer;
}