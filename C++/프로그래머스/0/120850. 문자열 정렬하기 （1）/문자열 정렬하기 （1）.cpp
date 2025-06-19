#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    
    for(const auto c: my_string) {
        // c는 소문자 또는 숫자임.
        if (!(c >= 'a' && c <= 'z')) {
            answer.push_back(c - '0');
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}