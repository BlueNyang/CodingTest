#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string my_string) {
    size_t strlen = my_string.length();
    vector<string> answer;
    answer.reserve(strlen);
    
    for(int i = 0; i < strlen; i++) {
        answer.emplace_back(my_string.substr(i));
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}