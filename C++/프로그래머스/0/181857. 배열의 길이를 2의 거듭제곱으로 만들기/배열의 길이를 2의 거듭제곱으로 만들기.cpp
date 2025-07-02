#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int len = 1;
    while (arr.size() > len) {
        len *= 2;
    }
    
    vector<int> answer(arr);
    
    for(size_t i = answer.size(); i < len; i++) {
        answer.emplace_back(0);
    }
    
    return answer;
}