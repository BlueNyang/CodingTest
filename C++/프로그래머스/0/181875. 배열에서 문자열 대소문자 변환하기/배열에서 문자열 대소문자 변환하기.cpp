#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer(strArr);
    size_t len = answer.size();
    
    for (size_t i = 0; i < len; i++) {
        transform(answer[i].begin(), answer[i].end(),
                  answer[i].begin(), [&](unsigned char c){
                     if(i % 2) return toupper(c);
                     else return tolower(c);
                 });
    }
    
    return answer;
}