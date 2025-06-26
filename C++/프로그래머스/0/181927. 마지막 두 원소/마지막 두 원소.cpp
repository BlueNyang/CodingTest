#include <string>
#include <vector>

using namespace std;

vector<int> solution(const vector<int> num_list) {
    // 원본 훼손 방지
    vector<int> answer(num_list);
    // iterator로 접근
    auto last = answer.end() - 1;
    
    if (*last > *(last - 1)) answer.push_back(*last - *(last - 1));
    else answer.push_back(2 * *last);
    
    return answer;
}