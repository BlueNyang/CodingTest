#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start_num, int end_num) {
    vector<int> answer;
    answer.reserve(start_num - end_num + 1);
    
    for (int i = start_num; i >= end_num; i--) {
        answer.emplace_back(i);
    }
    
    return answer;
}