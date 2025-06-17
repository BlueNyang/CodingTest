#include <string>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    
    // 미리 공간을 할당 (최적화)
    answer.reserve(my_string.length() * n);
    
    for(const auto c: my_string) {
        answer.append(n, c);
    }
    
    return answer;
}