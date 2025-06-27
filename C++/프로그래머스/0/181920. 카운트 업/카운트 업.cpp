#include <string>
#include <vector>

std::vector<int> solution(int start_num, int end_num) {
    std::vector<int> answer;
    answer.reserve(end_num - start_num + 1);
    
    for (int i = start_num; i <= end_num; i++)
        answer.push_back(i);
    
    return answer;
}