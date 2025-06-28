#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52, 0);
    
    for (const char& c: my_string) {
        if (c >= 'A' && c <= 'Z') {
            answer[c - 'A']++;
        } else {
            answer[c - 'a' + 26]++;
        }
    }
    
    return answer;
}